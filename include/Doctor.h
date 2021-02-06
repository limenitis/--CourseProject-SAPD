#pragma once
#include ".\..\include\Schedule.h"

class Doctor
{
protected:
    Schedule schedule;
    int cabinet_number;
    char doctor_name[25] = {'\0'};
    char specialization[50] = {'\0'}; 

public:
    Doctor();

    void set_schedule(Time start_time, Time finish_time);
    void set_schedule(char str[12]);
    void set_cabinet_number(int number);
    void set_doctor_name(char* name);
    void set_specialization(char* spec);

    bool check_doctor_data();
};

