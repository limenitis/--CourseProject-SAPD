#include <iostream>
#include ".\..\include\Date.h"
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
        char str[11]{ '1','5','.','0','1', '.', '2', '0', '2', '0', '\0' };

        Date t1;
        Date t2(12, 1, 2021);
        Date t3(str);

        char* time1 = t1.get_date();
        char* time2 = t2.get_date();
        char* time3 = t3.get_date();

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;

        cout << endl;

        t1.set_date(80, 80, -100);
        t2.set_date(-1, -1, -10);
        t3.set_date(30, 2, 2002);

        cout << t1 << endl;
        cout << t2 << endl;
        cout << t3 << endl;

        cout << endl;

        int i;
        i = 0;
        while(time1[i] != '\0')
        {
            cout << time1[i];
            i++;
        }
        cout << endl;

        i = 0;
        while(time2[i] != '\0')
        {
            cout << time2[i];
            i++;
        }
        cout << endl;

        i = 0;
        while(time3[i] != '\0')
        {
            cout << time3[i];
            i++;
        }
        cout << endl;
    }

    DumpMemoryLeaks

    return 0;
}

