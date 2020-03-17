#include <windows.h>
#include <stdio.h>

int main() {
	HWND target = FindWindow("ATL:002AE750", NULL);
	
	if (target != NULL) {
		LPARAM  ButtonPos = MAKELONG(100, 410);
		
		ShowWindow(target, SW_HIDE);
		SendMessage(target, WM_LBUTTONDOWN, 0, ButtonPos);
		SendMessage(target, WM_LBUTTONUP, 0, ButtonPos);
	}
	
	return 0;
}
