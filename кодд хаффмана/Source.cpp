#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    cout << "	" << " _   _          __   __                          " << endl;
    cout << "	" << "| | | |        / _| / _|                         " << endl;
    cout << "	" << "| |_| | _   _ | |_ | |_  _ __ ___    __ _  _ __  " << endl;
    cout << "	" << "|  _  || | | ||  _||  _|| '_ ` _ \\  / _` || '_ \\ " << endl;
    cout << "	" << "| | | || |_| || |  | |  | | | | | || (_| || | | |" << endl;
    cout << "	" << "\\_| |_/ \\__,_||_|  |_|  |_| |_| |_| \\__,_||_| |_|" << endl;
    cout << "	" << "c o d i n g " << endl << endl;
    ifstream F;
    F.open("Text.txt");
    int alf[256];
    for (int i = 0; i < 256; i++)
    {
        alf[i] = 0;
    }
    char s;
    F >> s;
    while (F)
    {
        alf[s]++;
        F >> s;  
    }
    for (int i = 0; i < 256; i++)
    {
        cout << "alf[" << i << "] = " << alf[i] << endl;
    }
    int col = 0;
    for (int i = 0; i < 256; i++)
    {
        if (alf[i] != 0)col++;
    }
    int* mas = new int[col+1];
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        if (alf[i] != 0) { mas[j] = i; j++; }
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (mas[j] > mas[j + 1]) {
                int b = mas[j]; // создали дополнительную переменную
                mas[j] = mas[j + 1]; // меняем местами
                mas[j + 1] = b; // значения элементов
            }
        }
    }
    for (int i = 0; i < col; i++)
    {
        cout << "mas[" << i << "]=" << (char)mas[i]<<endl;
    }

    return 0;



}
