#include <Windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include <string.h>

typedef LONG(__stdcall *RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

#define SE_DEBUG_PRIVILEGE 20

DWORD FindProcess(char *ProcessName)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return -1;
	}

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(hProcessSnap, &pe))
	{
		CloseHandle(hProcessSnap);
		return -1;
	}

	do
	{
		if (!strcmp(pe.szExeFile, ProcessName))
		{
			CloseHandle(hProcessSnap);
			return pe.th32ProcessID;
		}
	} while (Process32Next(hProcessSnap, &pe));

	CloseHandle(hProcessSnap);
	return 0;
}

int main() {
	//Get elevated privilege
	HMODULE hMod = LoadLibrary("ntdll");
	RtlAdjustPrivilege lpfnRtlAdjustPrivilege = (RtlAdjustPrivilege)GetProcAddress(hMod, "RtlAdjustPrivilege");
	if (lpfnRtlAdjustPrivilege == 0) {
		MessageBox(NULL, "Failed to get address of RtlAdjustPrivilege!\n", "Error", MB_OK | MB_ICONEXCLAMATION);
		return 1;
	}
	BOOLEAN dummy = 0;
	int rtn = lpfnRtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &dummy);
	if (rtn != 0)
	{
		printf("RtlAdjustPrivilege failed! %i\n", rtn);
	}
	
	DWORD TargetPid = FindProcess("HipsDaemon.exe");
	if (TargetPid <= 0)
	{
		MessageBox(NULL, "Can't find HipsDaemon.exe!", "Error", 0);
		return -1;
	}

	HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hThreadSnap == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	THREADENTRY32 te;
	te.dwSize = sizeof(THREADENTRY32);
	if (!Thread32First(hThreadSnap, &te))
	{
		CloseHandle(hThreadSnap);
		return 0;
	}

	do
	{
		if (te.th32OwnerProcessID == TargetPid)
		{
			HANDLE hThread = OpenThread(THREAD_TERMINATE, 0, te.th32ThreadID);
			if (hThread != 0)
			{
				TerminateThread(hThread, 0);
			}
			else
			{
				printf("TerminateHipsDaemon: OpenThread failed! %i\n", GetLastError());
			}
			CloseHandle(hThread);
		}
	} while (Thread32Next(hThreadSnap, &te));

	CloseHandle(hThreadSnap);
	return 0;
}
