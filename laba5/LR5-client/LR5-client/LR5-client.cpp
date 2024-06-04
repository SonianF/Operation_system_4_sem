#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DWORD dwBytes;
	HANDLE pipe;
	cout << "Введите тип гладиатора (самниты или фракийцы) >> ";
	char name[256];
	cin >> name;
	while ((strcmp(name, "самниты") != 0 && (strcmp(name, "фракийцы") != 0))) {
		cout << "Неправильное имя типа, пожалуйста, введите еще раз" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> name;
	}
	pipe = CreateFile(
		TEXT("\\\\.\\pipe\\mypipe1"),
		GENERIC_READ | GENERIC_WRITE,
		NULL,
		NULL,
		OPEN_EXISTING, 
		NULL, 
		NULL);
	if (pipe == INVALID_HANDLE_VALUE) {
		cout << "Ошибка создания именованного канала" << endl;
		return 0;
	}
	if (!WriteFile(pipe, name, sizeof(name), &dwBytes, NULL))
	{
		cout << "Ошибка" << endl;
		CloseHandle(pipe);
		return 1;
	}
	if (ReadFile(pipe, &name, sizeof(name), &dwBytes, NULL))
	{
		cout << name << endl;
		Sleep(1000);
	}
	CloseHandle(pipe);
	return 0;
}
