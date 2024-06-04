#include "C:\Users\Mi\source\repos\LR6_Server\LR6_Server\Server.h"
#include "C:\Users\Mi\source\repos\LR6_Client\LR6_Client\Client.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <TlHelp32.h>
using namespace std;
using namespace LR6Server; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Server);
    return 0;
}
HANDLE glad[2] = {
CreateEvent(NULL,FALSE,FALSE,L"S"),
CreateEvent(NULL,FALSE,FALSE,L"T"),
};
HANDLE win[3] = {
CreateEvent(NULL,FALSE,FALSE,L"+"),
CreateEvent(NULL,FALSE,FALSE,L"-"),
CreateEvent(NULL,FALSE,FALSE,L"N"),
};
int sampoints = 0;
int thrpoints = 0;
vector<int> samnits;
vector<int> thracians;
