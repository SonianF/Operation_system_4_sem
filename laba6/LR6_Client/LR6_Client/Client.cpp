#include "Client.h"
#include <Windows.h>
using namespace LR6Client;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Client);
	return 0;
}