#include ".\..\include\Patient.h"

Patient::Patient()
{
    year_born = 0;
}

void Patient::set_reg_num (int area_number, int serial_number)
{
    reg_num.set_reg(area_number, serial_number);
}

void Patient::set_name (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        patient_name[i] = str[i];
    }
    patient_name[i] = '\0';
}

void Patient::set_work (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        work_place[i] = str[i];
    }
    work_place[i] = '\0';
}

void Patient::set_addres (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        addres[i] = str[i];
    }
    addres[i] = '\0';
}

void Patient::set_year_born (int val)
{
    year_born = val;
}

bool Patient::check_patient_data()
{
    if (year_born < 1000)   { return true;  }
    else                    { return false; }
}

