#include <windows.h>
#include <stdio.h>

int main() {
	HWND target = FindWindow("HRMAINTRAY", NULL);
	if (target != NULL) {
		UINT i;
		
		for (i = 0; i < 0xffff; i++) {
			SendMessage(target, i, 0, 0);
		}
	}
	else {
		printf("Window not found\n");
	}
	
	return 0;
}
