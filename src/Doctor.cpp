#include ".\..\include\Doctor.h"

using namespace std;

Doctor::Doctor()
{
    cabinet_number = 0;
}

void Doctor::set_schedule(Time start_time, Time finish_time)
{
    schedule.set_schedule(start_time, finish_time);
}

void Doctor::set_schedule(char str[12])
{
    schedule.set_schedule(str);
}

void Doctor::set_cabinet_number(int number)
{
    cabinet_number = number;
}

void Doctor::set_doctor_name(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        doctor_name[i] = str[i];
    }
    doctor_name[i] = '\0';
}

void Doctor::set_specialization(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        specialization[i] = str[i];
    }
    specialization[i] = '\0';

}

bool Doctor::check_doctor_data()
{
    if (cabinet_number > 0 && schedule.check_schedule()) { true;  }
    else                                                 { false; }
}

Schedule Doctor::get_schedule ( void )
{
    return schedule;
}

int Doctor::get_cabinet_number ( void )
{
    return cabinet_number;
}

char* Doctor::get_doctor_name ( void )
{
    return doctor_name;
}

char* Doctor::get_specialization ( void )
{
    return specialization;
}

