// метод Гаусса для решения системы уравнений
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <cmath>
using namespace std;

void help()
{
    cout << "Справка:\n"
         << "Чтобы решить систему уравнений методом Гаусса, запустите программу без ключей\n";
    cout << "Для смены функции вычисления измените function() в исходном коде программы\n>_<\n";
}

// Неименнованные каналы связи in и out
int pipe_in[2]; // канал, с помощью которого мы записываем данные в дочерний процесс
// первый элемент массива используется для чтения из канала, второй - для записи
int pipe_out[2];
pid_t pid;

struct GAUSS
{
    int n;      // количество уравненйи
    double **a; // коэффециенты
    double *y;  // значения уравнений
    double *x;  // массив с корнями
};

int read_int(const string &msg) // ввод количества уравнений
{
    int result;
    string input;
    bool flag = true;
    while (flag)
    {
        cout << msg;
        cin >> result;
        if ((result <= 1) || (cin.fail() || (cin.peek() != '\n')))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " > Ошибка ввода, попробуйте еще раз\n";
        }
        else
        {
            flag = false;
        }
    }
    return result;
}

double read_double(int &i, int &j, bool var) // ввод коэффециетнов и значений
{
    double result;
    // string result;
    bool flag = true;
    while (flag)
    {
        if (var == 1)
            cout << "a[" << i + 1 << "][" << j + 1 << "]= ";
        else
            cout << "y[" << i + 1 << "]= ";
        cin >> result;
        if ((cin.fail() || (cin.peek() != '\n')))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " > Ошибка ввода, попробуйте еще раз\n";
        }
        else
        {
            flag = false;
        }
    }
    return result;
}

double *gauss(double **a, double *y, int n)
{
    double *x, max;
    int k, index;
    const double eps = 0.00001; // точность
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps)
                continue; // для нулевого коэффициента пропустить
            for (int j = k; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)
                continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}

void sysout(double **a, double *y, int n) // Вывод системы уравнений
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << y[i] << endl;
    }
    return;
}

void writeToPipe(int fd, GAUSS &data)
{
    write(fd, &data.n, sizeof(int));
    for (int i = 0; i < data.n; ++i)
    {
        for (int j = 0; j < data.n; ++j)
        {
            write(fd, &data.a[i][j], sizeof(double));
        }
        write(fd, &data.y[i], sizeof(double));
        write(fd, &data.x[i], sizeof(double));
    }
}

void readFromPipe(int fd, GAUSS &data)
{
    // read(fd, &data.n, sizeof(int));
    // double **a = new double *[data.n];
    // for (int i = 0; i < data.n; ++i)
    // {
    //     data.a[i] = new double[data.n];
    // }
    // double *y = new double[data.n];
    // double *x = new double[data.n];

    for (int i = 0; i < data.n; ++i)
    {
        for (int j = 0; j < data.n; ++j)
        {
            read(fd, &data.a[i][j], sizeof(double));
        }
        read(fd, &data.y[i], sizeof(double));
        read(fd, &data.x[i], sizeof(double));
    }
}

void frontend()
{
    GAUSS data;
    data.n = read_int("Введите количество уравнений: ");
    data.a = new double *[data.n];
    data.y = new double[data.n];
    data.x = new double[data.n];
    for (int i = 0; i < data.n; i++)
    {
        data.a[i] = new double[data.n];
        for (int j = 0; j < data.n; j++)
        {
            data.a[i][j] = read_double(i, j, true);
        }
    }
    for (int i = 0, j = 1; i < data.n; i++)
    {
        data.y[i] = read_double(i, j, 0);
        data.x[i] = 0;
    }
    sysout(data.a, data.y, data.n);
    writeToPipe(pipe_in[1], data);

    read(pipe_in[0], &data.n, sizeof(int)); //!!!!!!
    readFromPipe(pipe_out[0], data);

    sysout(data.a, data.y, data.n);
    cout << "Результат: " << endl;
    for (int i = 0; i < data.n; i++)
    {
        cout << "x[" << i + 1 << "]= " << data.x[i] << endl;
    }
    for (int i = 0; i < data.n; ++i)
        delete[] data.a[i];
    delete[] data.a;

    delete[] data.x;
    delete[] data.y;
    exit(0);
}

void backend()
{
    GAUSS data;
    read(pipe_in[0], &data.n, sizeof(int));
    data.a = new double *[data.n];
    for (int i = 0; i < data.n; ++i)
    {
        data.a[i] = new double[data.n];
    }
    data.y = new double[data.n];
    data.x = new double[data.n];
    readFromPipe(pipe_in[0], data);
    sysout(data.a, data.y, data.n);
    data.x = gauss(data.a, data.y, data.n);
    sysout(data.a, data.y, data.n);
    writeToPipe(pipe_out[1], data);
cout<<"written\n";
    for (int i = 0; i < data.n; ++i)
        delete[] data.a[i];
    delete[] data.a;

    delete[] data.x;
    delete[] data.y;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, 0);
    if (argc == 2 && !strcmp(argv[1], "--help"))
    {
        help();
        exit(0);
    }
    else if (argc != 1)
    {
        cout << "Запустите программу с ключом --help для получения справки" << endl;
        exit(1);
    }
    else
    {
        cout << "Программа для нахождения корней системы уравнений методом Гаусса\n";
        pipe(pipe_in);
        pipe(pipe_out);
        pid = fork();
        if (pid < 0)
        {
            cerr << "Критическая ошибка! Форк не создан" << endl;
            exit(1);
        }
        else if (pid > 0)
        {
            frontend();
            cout << 1 << endl;
        }
        else
        {
            backend();
        }
        for (int i = 0; i < 2; ++i)
        {
            close(pipe_in[i]);
            close(pipe_out[i]);
        }
    }
    // return 0;
}