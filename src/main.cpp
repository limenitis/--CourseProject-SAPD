#include <iostream>
#include ".\..\include\Time.h"
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
        char str[6]{ '1','5',':','0','0','\0' };

        Time t1;
        Time t2(12, 00);
        Time t3(str);

        char* time1 = t1.get_time();
        char* time2 = t2.get_time();
        char* time3 = t3.get_time();

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;

        cout << endl;

        for (int i = 0; i < 6; i++)
        {
            cout << time1[i];
        }
        cout << endl;

        for (int i = 0; i < 6; i++)
        {
            cout << time2[i];
        }
        cout << endl;

        for (int i = 0; i < 6; i++)
        {
            cout << time3[i];
        }
        cout << endl;
    }

    DumpMemoryLeaks

    return 0;
}

