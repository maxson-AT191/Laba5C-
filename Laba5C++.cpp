#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <cctype>
using namespace std;
struct base
{
    char Marka[56];
    char color[30];
    int SerialNumber;
    int RegisterNumber;
    int YearOfOissue;
    int ExpectionYear;
    int Cost;
};
void task1()
{
    /*
    Создать структуру Автомобиль организовать ее запись и чтение из файла Вывести данные про автомобили которым больше 2-х лет.
    */
    int const MAX = 2; 
    base b[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        cout << "\nInput Marka: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(b[i].Marka, 56);
        cout << "\nInput Color: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(b[i].color, 30);
        cout << "\nInput SerialNumber: ";
        cin >> b[i].SerialNumber;
        cin.ignore(32767, '\n');
        cout << "\nInput RegisterNumber: ";
        cin >> b[i].RegisterNumber;
        cin.ignore(32767, '\n');
        cout << "\nInput YearOfOissue: ";
        cin >> b[i].YearOfOissue;
        cin.ignore(32767, '\n');
        cout << "\nInput ExpectionYear: ";
        cin >> b[i].ExpectionYear;
        cin.ignore(32767, '\n');
        cout << "\nInput Cost: ";
        cin >> b[i].Cost;
        cin.ignore(32767, '\n');
    }
   
    ofstream outfile;
    outfile.open("Out.txt");
    for (int i = 0; i < MAX; ++i)
        outfile << "\nMarka: " << b[i].Marka << endl << "\nColor: " << b[i].color << endl<< "\nSerialNumber: " << b[i].SerialNumber<<endl<< "\nRegisterNumber: " << b[i].RegisterNumber<<endl<< "\nYearOfOissue: " << b[i].YearOfOissue<<endl<< "\nExpectionYear: " << b[i].ExpectionYear<<endl<< "\nCost: " << b[i].Cost<<endl;
        
    
    for (int i = 0; i < MAX; ++i) {
        if (2020 - b[i].YearOfOissue > 2) {
            outfile << "Car which year of issue more than 2 years: " << endl<<endl;
            outfile << "\nMarka: " << b[i].Marka << endl << "\nColor: " << b[i].color << endl << "\nSerialNumber: " << b[i].SerialNumber << endl << "\nRegisterNumber: " << b[i].RegisterNumber << endl << "\nYearOfOissue: " << b[i].YearOfOissue << endl << "\nExpectionYear: " << b[i].ExpectionYear << endl << "\nCost: " << b[i].Cost << endl;

        }
    }
    outfile.close();
    ifstream infile;
    infile.open("Out.txt");
    if (!infile.is_open()) {
        cout << "ERROR";
    }
    else {
        cout << "File was opened"<<endl;
        char ch;
        while (infile.get(ch)) {
            cout << ch;
        }
    }
    infile.close();
    system("pause");
    
}

void task2() {
    /*
    Дан символьный файл.Определить явлюются ли два первых символа файла цифрами,если установить является ли число образованное этими цифрами четным
    */
    ofstream outfile1;
    outfile1.open("Out1.txt");
    char m[4];
    if (!outfile1.is_open()) {
        cout << "Error"<<endl;
    }
    else {
        for (int i = 0; i < 4; ++i) {
            cin >> m[i];
            outfile1 << m[i]<<" "<<endl;
        }
        if (isdigit(m[0]) && isdigit(m[1])) {
            outfile1 << "First and second are  numbers"<<endl;
            outfile1 << "First and second elements: " << m[0] << m[1] << endl;
            if (m[1] % 2 == 0) {
                outfile1 << "It is even number" << endl;
            }
            else {
                outfile1 << "It is odd number" << endl;
            }
        }
        else {
            outfile1 << "One of those elements arent numbers"<<endl;
        }
 
    }
    outfile1.close();
    ifstream infile1;
    infile1.open("Out1.txt");
    if (!infile1.is_open()) {
        cout << "ERROR";
    }
    else {
        cout << "File was opened" << endl;
        char ch;
        while (infile1.get(ch)) {
            cout << ch;
        }
    }
    infile1.close();
}




void hard();
void CheckDigit(unsigned& anydigit);
void DisplayMatrix(int* Pointer, unsigned n, unsigned m);
int* InitMatrix(unsigned l, unsigned n, unsigned m);
int* FreeMemory(unsigned n, unsigned m);
int BlockWriteFile(const char* FileName, unsigned count_matrix, unsigned row, unsigned col);
void DisplayFile(const char* FileName, int count_matrix, unsigned n, unsigned m);
void WorkFunc(string FileNameFirst, string FileNameSec, int count_matrix1, int count_matrix2, int row, int col);
void Delete(string filename2, string filename3, int count1, int count2, int row = 2, int col = 2);




    void task3()
    {
        setlocale(LC_ALL, "Russian");
        srand(time(NULL));
        hard();

    }

 
    void hard()
    {
        /*
    В первом файле хранится k матриц порядка m × n, во втором - l матриц. Поменять местами все нечетные (1, 3, 5,… по
    порядковому номеру в файле) матрицы из первого файла с четными матрицами (0, 2, 4, …) второго файла (до конца меньшего
    из файлов). Оставшиеся в большем файле матрицы переписать в третий файл. Вывести на экран содержимое первого и второго
    файлов
       */
        system("cls");
        printf("\nHard level task: \n");
        unsigned k = 4, l = 5,
            row, col;

        cout << "\nЗадано количество матриц(mxn) k=4 l=5: \n";
        printf("\nВведите размерность матриц(m x n): \n\tколичество строк: "); CheckDigit(row);
        printf("\tКоличество столбцов: "); CheckDigit(col);

        std::string filename = "firstfile.txt",
            secfilen = "secndfile.txt",
            thirfile = "thirdfile.txt";

        cout << "\nСодержимое файлов до внесенных изменений: \n";
        cout << "\nСодержимое 1-го файла до внесенных изменений: \n";
        BlockWriteFile(secfilen.c_str(), l, row, col);
        DisplayFile(secfilen.c_str(), l, row, col);

        cout << "\nСодержимое 2-го файла до внесенных изменений: \n";
        BlockWriteFile(filename.c_str(), k, row, col);
        DisplayFile(filename.c_str(), k, row, col);


        cout << "\nСодержимое файлов после внесенных изменений: \n";
        Delete(secfilen, thirfile, k, l, row, col);
        WorkFunc(filename, secfilen, k, l, row, col);
        cout << "\nСодержимое 1-ого файлa после внесенных изменений: \n";
        DisplayFile(secfilen.c_str(), k, row, col);
        cout << "\nСодержимое 2-ого файлa после внесенных изменений: \n";
        DisplayFile(filename.c_str(), k, row, col);
        int var = l > k ? (l - k) : (k - l);
        cout << "\nСодержимое 3-ого файлa после внесенных изменений: \n";
        DisplayFile(thirfile.c_str(), var, row, col);

        cout << "\nНажми Enter для завершения Task Hard...\n";
        getchar();
    }

    void Delete(string filename2, string filename3, int count1, int count2, int row, int col)
    {
        fstream f2, f3, temp;
        f2.open(filename2, ios::in);
        f3.open(filename3, ios::out);
        temp.open("temp.txt", ios::out);
        int countmin = count1 < count2 ? count1 : count2,
            countmax = count1 > count2 ? count1 : count2;
        int var;
        int BufSize = sizeof(int) * row * col,
            counter_matrix = 0;

        int* Pointer = (int*)malloc(BufSize);
        unsigned i;
        string t;
        for (i = 0; i < countmax; i++)
        {

            if (i < countmin)
            {
                getline(f2, t);
                temp << t << "\n";
            }
            else
            {
                getline(f2, t);
                f3 << t << "\n";
            }
        }

        f2.close();
        f3.close();
        temp.close();

        f2.open(filename2, ios::out | ios::trunc);
        temp.open("temp.txt", ios::in);
        ifstream d;
        ofstream f;
        for (size_t i = 0; i < countmin; i++)
        {
            string t;
            getline(temp, t);
            f2 << t << "\n";
        }
        f2.close();
        temp.close();

    }

    void WorkFunc(string FileNameFirst, string FileNameSecon, int count_matrix1, int count_matrix2, int row, int col)
    {
        fstream f_out_in1; f_out_in1.open(FileNameFirst, ios::in);
        fstream f_out_in2; f_out_in2.open(FileNameSecon, ios::in);

        if (!f_out_in1.is_open()) { printf("\nCan't open file to read."); getchar(); abort(); }
        if (!f_out_in2.is_open()) { printf("\nCan't open file to read."); getchar(); abort(); }

        int count_mat = count_matrix1 < count_matrix2 ? count_matrix1 : count_matrix2;

        fstream f_t1, f_t2;
        f_t1.open("f_t1.txt", ios::out);
        f_t2.open("f_t2.txt", ios::out);
        string str1, str2;
        for (size_t j = 0; j < count_mat; j++)
        {
            if (j % 2 == 0) {
                getline(f_out_in1, str1);
                f_t1 << str1 << endl;
                getline(f_out_in2, str2);
            }
            else
            {
                getline(f_out_in1, str1);
                f_t1 << str2 << endl;
                getline(f_out_in2, str1);
            }
        }
        f_out_in1.seekg(0, ios::beg);
        f_out_in2.seekg(0, ios::beg);
        f_t1.close();
        for (size_t j = 0; j < count_mat; j++)
        {
            if (j % 2 == 0) {
                getline(f_out_in1, str1);
            }
            else
            {
                getline(f_out_in1, str2);
                f_t2 << str2 << endl;
                getline(f_out_in2, str1);
                getline(f_out_in2, str2);
                f_t2 << str2 << endl;
            }
        }
        f_out_in1.close();
        f_out_in2.close();
        f_t2.close();

        f_out_in1.open(FileNameFirst, ios::out | ios::trunc);
        f_out_in2.open(FileNameSecon, ios::out | ios::trunc);
        f_t1.open("f_t1.txt", ios::in);
        f_t2.open("f_t2.txt", ios::in);
        string tmp, tmp2;

        for (size_t j = 0; j < count_mat; j++)
        {
            getline(f_t1, tmp);
            f_out_in1 << tmp << endl;

            getline(f_t2, tmp2);
            f_out_in2 << tmp2 << endl;
        }
        f_out_in1.close();
        f_out_in2.close();
        f_t1.close();
        f_t2.close();
    }

    void CheckDigit(unsigned& anydigit)
    {
        while (true)
        {
            std::cin >> anydigit;
            if (!isalpha(anydigit) && !isspace(anydigit))
                break;
            if (cin.bad() || cin.fail())
            {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            std::cout << "\nНекоректный ввод числового значения, повторите ввод!!!\n";
        }
    }

    void DisplayMatrix(int* Pointer, unsigned n, unsigned m)
    {
        unsigned i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%4d", *(Pointer + i * m + j));
            }
            printf("\n");
        }
    }

    int* InitMatrix(unsigned l, unsigned n, unsigned m)
    {
        unsigned i;
        int* Pointer = (int*)malloc(n * m * sizeof(int));
        for (i = 0; i < n * m; i++) { Pointer[i] = rand() % 10; }
        return Pointer;
    }

    int* FreeMemory(unsigned n, unsigned m)
    {
        int* Pointer = (int*)malloc(n * m * sizeof(int));
        return Pointer;
    }


    int BlockWriteFile(const char* FileName, unsigned count_matrix, unsigned row, unsigned col)
    {
        int BufSize = sizeof(int) * row * col,
            counter_matrix = 0;

        int* Pointer = (int*)malloc(BufSize);
        unsigned i;

        ofstream f_out;
        f_out.open(FileName, ios::out | ios::trunc);

        if (!f_out.is_open())
        {
            printf("Can't open file to write.");
            getchar();
            abort();
        }

        for (i = 0; i < count_matrix; i++)
        {
            Pointer = InitMatrix(i, row, col);
            for (size_t j = 0; j < row * col; j++)
            {
                f_out << Pointer[j] << " ";
            }
            f_out << "\n";

        }
        f_out.close();
        return counter_matrix;
    }


    void DisplayFile(const char* FileName, int count_matrix, unsigned n, unsigned m)
    {
        int BufSize = sizeof(int) * n * m, Sector = 0;
        int* Pointer = FreeMemory(n, m);

        ifstream f_in;
        f_in.open(FileName, ios::in);

        if (!f_in.is_open()) { printf("\nCan't open file to read."); getchar(); abort(); }

        for (size_t j = 0; j < count_matrix; j++)
        {
            int i = 0, q = 0;
            while (f_in >> Pointer[i] && i < (n * m) - 1) { i++; }
            printf("\n %d's  matrix \n", (Sector + 1));
            DisplayMatrix(Pointer, n, m);

            Sector++;
        }
    }


int main() {
    task1();
    task2();
    task3();
}