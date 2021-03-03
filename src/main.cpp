#include <Windows.h>
#include <iostream>
#include ".\..\include\Hospital.h"
// #include ".\..\include\str-tools.h"

using namespace std;

// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>
// #ifdef _DEBUG
//     #ifndef DBG_NEW
//     #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//     #define newDBG_NEW
//     #endif
// #endif

// #define DumpMemoryLeaks                                \
// _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);       \
// _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);     \
// _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);      \
// _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);    \
// _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);     \
// _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);   \
// _CrtDumpMemoryLeaks();


void patients_menu(Hospital* hospital);
void doctors_menu(Hospital* hospital);
void directions_menu(Hospital* hospital);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        Hospital* hospital = new Hospital;

        int key;
        while (1)
        {
            //cout << "|  mode   :                           |" << endl;

            cout << "+ ----------------------------------- +" << endl;
            cout << "| :::::::::::: Main menu :::::::::::: |" << endl;
            cout << "+ ----------------------------------- +" << endl;
            cout << "|  mode 1 : patients menu             |" << endl;
            cout << "|  mode 2 : doctors menu              |" << endl;
            cout << "|  mode 3 : directions menu           |" << endl;
            cout << "|  mode 4 : exit                      |" << endl;
            cout << "+ ----------------------------------- +" << endl;
            cin >> key;

            if (key == 1)
            {
                patients_menu(hospital);
            }
            else if (key == 2)
            {
                doctors_menu(hospital);
            }
            else if (key == 3)
            {
                directions_menu(hospital);
            }
            else
            {
                break;
            }
        }

        delete hospital;

    }
    // DumpMemoryLeaks

    return 0;
}

void patients_menu(Hospital *hospital)
{
    int patient_key;
    while (true)
    {
        //cout << "|  mode   :                           |" << endl;

        cout << "+ ----------------------------------- +" << endl;
        cout << "| :::::::::: Patients menu :::::::::: |" << endl;
        cout << "+ ----------------------------------- +" << endl;
        cout << "|  mode 1 : insert patient            |" << endl;
        cout << "|  mode 2 : remove patient            |" << endl;
        cout << "|  mode 3 : print  patient            |" << endl;
        cout << "|  mode 4 : print  patients           |" << endl;
        cout << "|  mode 5 : clear  patients           |" << endl;
        cout << "|  mode 6 : find patient by name      |" << endl;
        cout << "|  mode 7 : find patient by reg num   |" << endl;
        cout << "|  mode 8 : exit                      |" << endl;
        cout << "+ ----------------------------------- +" << endl;
        cin >> patient_key;

        if (patient_key == 1)
        {
            hospital->insert_patient();
        }
        else if (patient_key == 2)
        {
            hospital->remove_patient();
        }
        else if (patient_key == 3)
        {
            hospital->print_patient();
        }
        else if (patient_key == 4)
        {
            hospital->print_patients();
        }
        else if (patient_key == 5)
        {
            hospital->clear_patients();
        }
        else if (patient_key == 6)
        {
            hospital->find_patient_by_name();
        }
        else if (patient_key == 7)
        {
            hospital->find_patient_by_reg_num();
        }
        else
        {
            break;
        }
    }
}

void doctors_menu(Hospital* hospital)
{
    int doctors_key;
    while (true)
    {
        //cout << "|  mode   :                           |" << endl;

        cout << "+ ---------------------------------- +" << endl;
        cout << "| :::::::::: Doctors menu :::::::::: |" << endl;
        cout << "+ ---------------------------------- +" << endl;
        cout << "|  mode 1 : insert doctor            |" << endl;
        cout << "|  mode 2 : remove doctor            |" << endl;
        cout << "|  mode 3 : print  doctor            |" << endl;
        cout << "|  mode 4 : print  doctors           |" << endl;
        cout << "|  mode 5 : clear  doctors           |" << endl;
        cout << "|  mode 6 : find doctor by name      |" << endl;
        cout << "|  mode 7 : find doctor by post      |" << endl;
        cout << "|  mode 8 : exit                     |" << endl;
        cout << "+ ---------------------------------- +" << endl;
        cin >> doctors_key;

        if (doctors_key == 1)
        {
            hospital->insert_doctor();
        }
        else if (doctors_key == 2)
        {
            hospital->remove_doctor();
        }
        else if (doctors_key == 3)
        {
            hospital->print_doctor();
        }
        else if (doctors_key == 4)
        {
            hospital->print_doctors();
        }
        else if (doctors_key == 5)
        {
            hospital->clear_doctors();
        }
        else if (doctors_key == 6)
        {
            hospital->find_doctor_by_name();
        }
        else if (doctors_key == 7)
        {
            hospital->find_doctor_by_post();
        }
        else
        {
            break;
        }
    }
}


void directions_menu(Hospital* hospital){}
