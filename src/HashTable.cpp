#pragma once
#include "lab4.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fcntl.h>
#include <io.h>
#define cout wcout
#define cerr wcerr
#define cin wcin

using namespace std;

// Для обнаружения утечек памяти
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif
//
#define DumpMemoryLeaks  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT); _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE); _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT); _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE); _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT); _CrtDumpMemoryLeaks();

void set_table(HashTable* table);
void find_key(HashTable* table);
void delete_key(HashTable* table);
void push_key(HashTable* table);

int main()
{
    //system("chcp 1200");
    //system("chcp 1251");
    //system("chcp 65001");
    //system("cls");

    //HANDLE hStdin;
    //hStdin = GetStdHandle(GENERIC_WRITE);
    //SetConsoleMode(hStdin, ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    int input_int;
    HashTable* table = new HashTable;
    input_int = _setmode(_fileno(stdout), _O_U16TEXT);


    while (true) 
    {
        cout << L"╔══════════════════════════════════════════════════════════════╗  \n";
        cout << L"║                           Hash Table                         ║  \n";
        cout << L"╠══════════════════════════════════════════════════════════════╣  \n";
        cout << L"║  mode 1 : set    table                                       ║  \n";
        cout << L"║  mode 2 : print  table                                       ║  \n";
        cout << L"║  mode 3 : print  table : from -> to                          ║  \n";
        cout << L"║  mode 4 : print  table : id                                  ║  \n";
        cout << L"║  mode 5 : save   table                                       ║  \n";
        cout << L"║  mode 6 : find   key                                         ║  \n";
        cout << L"║  mode 7 : delete key                                         ║  \n";
        cout << L"║  mode 8 : push   key                                         ║  \n";
        cout << L"║  mode 9 : exit                                               ║  \n";
        cout << L"╚══════════════════════════════════════════════════════════════╝  \n";

        //cin.ignore(32767, '\n');
        cin >> input_int;

        switch (input_int)
        {
        case 1:
            set_table(table);
            green_out(L"OK");
            break;
        case 2:
            table->print();
            break;
        case 3:
            int from, to;
            cout << L"from = "; cin >> from;
            cout << L"to = "; cin >> to;
            table->print(from - 1, to);
            break;
        case 4:
            int id;
            cout << L"id = "; cin >> id;
            table->print(id - 1, id);
            break;
        case 5:
            table->save();
            green_out(L"OK");
            break;
        case 6:
            find_key(table);
            break;
        case 7:
            delete_key(table);
            break;
        case 8:
            push_key(table);
            break;
        case 9:
            delete table;
            DumpMemoryLeaks;
            return 0;
        default:
            red_out(L"error key");
            break;
        }
    }
}


void set_table(HashTable* table)
{
    for (int timer = 0; timer < 1500; timer++)
    {
        table->push_element(gen_rand_key());
    }
}

void find_key(HashTable* table)
{
    wstring key;
    cout << L"key = "; cin >> key;
    int id = table->find_key(key);
    if (id == -1) 
    {
        red_out(L"[find key] key don't found");
    }
    else 
    {
        cout << L"id = " << id + 1 << endl;
    }
}

void delete_key(HashTable* table) 
{
    wstring key;
    cout << L"key = "; cin >> key;
    table->del_element(key);
}

void push_key(HashTable* table) 
{
    wstring key;
    cout << L"key = "; cin >> key;
    table->push_element(key, 1);
}


