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

    // {
        // char str[12]{'1', '0', ':', '0', '0', '-', '1', '8', ':', '0', '0', '\0'};
        // Time t1;
        // Time t2;
        // Time* t1 = new Time;
        // Time* t2 = new Time;
        // Schedule s1;
        // Schedule s2(t1, t2);
        // Schedule s3(str);
        // char* time1 = s1.get_schedule();
        // char* time2 = s2.get_schedule();
        // char* time3 = s3.get_schedule();
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << s3 << endl;
        // cout << endl;
        // s1.set_schedule(t1, t2);
        // s2.set_schedule(str);
        // s3.set_schedule(str);
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << s3 << endl;
        // cout << endl;
    // }

    DumpMemoryLeaks

    return 0;
}

