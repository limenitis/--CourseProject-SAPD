#include <iostream>
#include ".\..\include\Schedule.h"
#include ".\..\include\str-tools.h"

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

    {
        char str[11]{ '1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0' };

        Schedule t1;
        Schedule t2(8, 235758);
        Schedule t3(str);

        char* time1 = t1.get_reg();
        char* time2 = t2.get_reg();
        char* time3 = t3.get_reg();

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;
        cout << endl;

        t1.set_schedule(12, 3414);
        t2.set_schedule(10, 334352);
        t3.set_schedule(5 , 2002);

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;
        cout << endl;

    }

    DumpMemoryLeaks

    return 0;
}

