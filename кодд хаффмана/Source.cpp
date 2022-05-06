#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
class tree_elem
{
public:
    int m_data;     //ключ
    tree_elem* m_left;    //указатель на левого потомка
    tree_elem* m_right;  //указатель на правого потомка олор
    tree_elem(int val)
    {
        m_left = nullptr;
        m_right = nullptr;
        m_data = val;
    }
};
class binary_tree
{
private:
    tree_elem* m_root;        //указатель на корень
    int m_size;                       //количество элементов в дереве
    void print_tree(tree_elem*);   //используется в рекурсивном алгоритме обхода дерева
    void delete_tree(tree_elem*); //используется в рекурсивном алгоритме удаления в дереве
public:
    binary_tree(int);      
    ~binary_tree();           
    void print();             //вывод всех элементов поддерева
    bool find(int);          //поиск элемента в дереве
    void insert(int);         //добавление нового элемента
    void erase(int);         //удаление узла с указанным ключом 
    int size();                  // возврат количества элементов в дереве 
};
binary_tree::binary_tree(int key)
{
    m_root = new tree_elem(key);
    m_size = 1;
}
binary_tree::~binary_tree()
{
    delete_tree(m_root);
}
void binary_tree::delete_tree(tree_elem* curr)
{
    if (curr)
    {
        delete_tree(curr->m_left);
        delete_tree(curr->m_right);
        delete curr;
    }
}
void binary_tree::insert(int key)
{
    tree_elem* curr = m_root;   //настройка на корень дерева
    while (curr && curr->m_data != key)  // цикл, пока keyключу текущего узла
    {
        if (curr->m_data > key && curr->m_left == NULL)
        {  //key меньше ключа текущего узла  и левая ссылка текущего узла NULL
            curr->m_left = new tree_elem(key);     //новый узел формируется по левой ветви
            ++m_size;
            return;
        }
        if (curr->m_data < key && curr->m_right == NULL)
        { //key больше ключа текущего узла  и правая ссылка текущего узла NULL
            curr->m_right = new tree_elem(key); //новый узел формируется по правой ветви
            ++m_size;
            return;
        }
        //Движение по левой или правой ветви родительского узла
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
}
void binary_tree::print()
{
    print_tree(m_root);
    cout << endl;
}
void binary_tree::print_tree(tree_elem* curr)
{
    if (curr)   // Проверка на ненулевой указаgfuygтель
    {
        print_tree(curr->m_left);
        cout << curr->m_data << " ";
        print_tree(curr->m_right);
    }
}





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
