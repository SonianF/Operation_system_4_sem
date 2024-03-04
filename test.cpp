#include <fcntl.h>
#include <sys/stat.h> // для получения данных о размере файла
//#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string defects() {
    cout << "Возникла ошибка!";
    return 0;
}

void cp() //копирование файлов
{
    cout << "Введите название копируемого файла: \n > ";
    string filename;
    cin >> filename;
    cout << "Введите название копии файла: \n > ";
    string newFilename;
    cin >> newFilename;
    //ошибка
    if (filename == newFilename) { //совпадают имена файлов
      
        return;
    }

    /*
size_t write(int fd,void * buf, size_t length), size_t write(int fd, const void * buf, size_t
length).
    */

    ifstream fin;
    size_t bufsize = 4;
    char* buf = new char[bufsize];
    fin.open(filename, ios::binary);
    if (fin.is_open()) {
        ofstream fout;
        fout.open(newFilename, ios::binary); //ios::binary - открытие файла в бинарном режиме
        while (!fin.eof()) { // читаем, пока не дошли конца файла
            fin.read(buf, bufsize); //байты из файла в указанную область памяти
            if (fin.gcount()) fout.write(buf, fin.gcount()); // write(Указатель на блок данных и количество байт, который этот блок занимает)
        }
        cout << " > Копирование прошло успешно!" << endl;
        delete[] buf;
        fin.close();
        fout.close();
    }
    else {
        
        return;
    }
}

void peremena()//перемещение файлов
{
    cout << "Введите название перемещающего файла файла: \n > ";
    string filename;
    cin >> filename;
    cout << "Введите название копии файла: \n > ";
    string newFilename;
    cin >> newFilename;
    //ошибка
    if (filename == newFilename) { //совпадают имена файлов
       // defects();
        return;
    }

    /*
size_t write(int fd,void * buf, size_t length), size_t write(int fd, const void * buf, size_t
length).
    */

    ifstream fin;
    size_t bufsize = 4;
    char* buf = new char[bufsize];
    fin.open(filename, ios::binary);
    if (fin.is_open()) {
        ofstream fout;
        fout.open(newFilename, ios::binary); //ios::binary - открытие файла в бинарном режиме
        while (!fin.eof()) { // читаем, пока не дошли конца файла
            fin.read(buf, bufsize); //байты из файла в указанную область памяти
            if (fin.gcount()) fout.write(buf, fin.gcount()); // write(Указатель на блок данных и количество байт, который этот блок занимает)
        }
        cout << " > Копирование прошло успешно!" << endl;
        delete[] buf;
        fin.close();
        fout.close();
    }
    else {
       // defects();
        return;
    }
}

string data() // получение информации о файле (права, размер, время изменения)
{
    int lstat(const char* pathname, struct stat* statbuf);
    int fstat(int fd, struct stat* statbuf);
    return 0;
}

void chmod() //изменение прав на выбранный файл
{

}

int main()
{
    cp();
    
}
