#include <Windows.h>
#include <iostream>
#include ".\..\include\Hospital.h"
// #include ".\..\include\str-tools.h"

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

#define DumpMemoryLeaks                                \
_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);       \
_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);     \
_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);      \
_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);    \
_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);     \
_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);   \
_CrtDumpMemoryLeaks();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        Hospital* hospital = new Hospital;

        int key = 0;
        while (key != 9)
        {
            cout << "+----------------------------+" << endl;
            cout << "|  mode 1 : add patient      |" << endl;
            cout << "|  mode 2 : del patient      |" << endl;
            cout << "|  mode 3 : print patient    |" << endl;
            cout << "+----------------------------+" << endl;
            cin >> key;

            if (key == 1)
            {
                hospital->add_patient();
            }
            else if (key == 2)
            {
                hospital->remove_patient();
            }
            else if (key == 3)
            {
                hospital->print_patients();
            }
            else
            {
                break;
            }
        }

        delete hospital;

    }
    DumpMemoryLeaks

    return 0;
}

