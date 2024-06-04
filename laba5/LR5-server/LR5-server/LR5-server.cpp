#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

HANDLE hMutex;

int N;
int n;

std::ofstream fout;   
HANDLE* pipes;

vector<int> samnits;
vector<int> thracians;
int sampoints = 0;
int thrpoints = 0;
STARTUPINFO si;//структура
PROCESS_INFORMATION pi;// структура с информацией о процесс

void result() {
    if (sampoints > thrpoints) {
        cout << "Побидели самниты!" << endl;
        fout << "Побидели самниты!" << endl;
    }
    else if (thrpoints > sampoints) {
        cout << "Победили фракийцы!" << endl;
        fout << "Победили фракийцы!" << endl;
    }
    else if (sampoints == 0 && thrpoints == 0) {
        cout << "Сражения не было, все участники одного типа" << endl;
        fout << "Победили фракийцы!" << endl;
    }
    else {
        cout << "Ничья" << endl;
        fout << "Ничья" << endl;
    }
    cout << "Ave, Caesar!" << endl;
    fout << "Ave, Caesar!" << endl;
}

void fight() {
    DWORD result = WaitForSingleObject(hMutex, 0);
    if (result != WAIT_OBJECT_0) 
    {
        WaitForSingleObject(hMutex, INFINITE); 
    }

    srand(time(NULL)); 
    int winner = rand() % 100;

    if (winner < 50) {
        int index = samnits[0];
        DWORD dwBytes;
        WriteFile(pipes[index], "Победитель", sizeof("Победитель"), &dwBytes, NULL);
        samnits.erase(samnits.begin()); //удаляем нулевой элемент
        CloseHandle(pipes[index]); //закрываем дескриптор
        index = thracians[0];
        WriteFile(pipes[index], "Проигравший", sizeof("Проигравший"), &dwBytes, NULL);
        thracians.erase(thracians.begin());
        CloseHandle(pipes[index]);
        ++sampoints;
    }
    else {
        int index = samnits[0];
        DWORD dwBytes;
        WriteFile(pipes[index], "Проигравший", sizeof("Проигравший"), &dwBytes, NULL);
        samnits.erase(samnits.begin());
        CloseHandle(pipes[index]);
        index = thracians[0];
        WriteFile(pipes[index], "Победитель", sizeof("Победитель"), &dwBytes, NULL);
        thracians.erase(thracians.begin());
        CloseHandle(pipes[index]);
        ++thrpoints;
    }
    cout << "Очки самнитов - " << sampoints << endl;
    cout << "Очки фракийцев - " << thrpoints << endl;
    ReleaseMutex(hMutex); //Для освобождения объекта
}

void AddGlad(int index) {
    char msg[256];
    DWORD dwBytes;
    if (!ReadFile(pipes[index], &msg, sizeof(msg), &dwBytes, NULL)) {
        cout << "Ошибка" << endl;
        CloseHandle(pipes[index]);
    }
    if (!strcmp(msg, "самниты")) {
        samnits.push_back(index);
        if (samnits.size() != 0 && thracians.size() != 0) {
            CreateThread(NULL, NULL,
                (LPTHREAD_START_ROUTINE)fight,  NULL, NULL, NULL);
        }
        else {
            if (n < N - 1) {
                cout << "Введите другой тип гладиатора для начала битвы, пожалуйста\n";
                ++n;
                HANDLE pipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\mypipe1"),  PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, 1, 1, 0, NULL);
                CreateProcess(L"C:\\Users\Mi\source\repos\LR5-client\LR5-client\x64\Debug\LR5-client.exe", NULL, NULL, 0, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
                while (true) {
                    if (ConnectNamedPipe(pipe, NULL)) {
                        fout << "Гладиатор " << n + 1 << " добавлен" << endl;
                        cout << "Гладиатор " << n + 1 << " добавлен" << endl;
                        break;
                    }
                }
                pipes[n] = pipe;
                AddGlad(n);
            }
            else {
                cout << "Остались гладиаторы только одного типа, они сражаться не могут" << endl;
            }
        }
    }
    else if (!strcmp(msg, "фракийцы")) {
        thracians.push_back(index);
        if (samnits.size() != 0 && thracians.size() != 0) {
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)fight, NULL, NULL, NULL);
        }
        else {
            if (n < N - 1) {
                cout << "Введите другой тип гладиатора для начала битвы, пожалуйста\n";
                ++n;
                HANDLE pipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\mypipe1"),
                    PIPE_ACCESS_DUPLEX,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES, 1, 1, 0, NULL);
                CreateProcess(L"C:\\Users\Mi\source\repos\LR5-client\LR5-client\x64\Debug\LR5-client.exe", NULL, NULL, 0, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
                while (true) {
                    if (ConnectNamedPipe(pipe, NULL)) {
                        cout << "Гладиатор " << n + 1 << " добавлен" << endl;
                        break;
                    }
                }
                pipes[n] = pipe;
                AddGlad(n);
            }
            else {
                cout << "Остались гладиаторы одного типа, они сражаться не могут" << endl;
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Леди и джентельмены, добро пожаловать на гладиаторские бои" << endl;
    hMutex = CreateMutex(NULL,  FALSE, TEXT("MyMutex"));
    cout << "Введите количество гладиаторов >> ";
    cin >> N;
    while (cin.good() != true || !(cin.peek() == '\n') || N < 2 || N > 50) 
    {
        cout << "Ошибка ввода, введите число >= 2: ";
        cin.clear();
        cin.ignore(512, '\n');
        cin >> N;
    }

    pipes = new HANDLE[N]; 

    for (n = 0; n < N; ++n) {
        HANDLE pipe = CreateNamedPipe(
            TEXT("\\\\.\\pipe\\mypipe1"), PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES,  1, 1, 0, NULL);
        CreateProcess(L"C:\\Users\Mi\source\repos\LR5 - client\x64\Debug\LR5 - client.exe", NULL,NULL, 0,  FALSE, CREATE_NEW_CONSOLE, NULL,  NULL,  &si, &pi);
        while (true) {
            if (ConnectNamedPipe(pipe, NULL)) {
                cout << "Гладиатор " << n + 1 << " добавлен" << endl;
                break;
            }
        }

        pipes[n] = pipe;
        AddGlad(n);
    }
    Sleep(2000);
    result();
    CloseHandle(hMutex);
    system("pause");
    return 0;
}