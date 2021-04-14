#include "Includes.h"
#include "Zula.h"


BOOL __stdcall DllMain(HINSTANCE hDll, DWORD _CallReason, LPVOID)
{
	switch (_CallReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hDll);
		MessageBoxA(0, "Injetado!", 0, 0);
		//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)voidZula, 0, 0, 0);
	}
	return 1;
}