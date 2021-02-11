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

    void set_schedule       (Time start_time, Time finish_time);
    void set_schedule       (char str[12]);
    void set_cabinet_number (int number);
    void set_doctor_name    (char* name);
    void set_specialization (char* spec);

    Schedule get_schedule       ( void );
    int      get_cabinet_number ( void );
    char*    get_doctor_name    ( void );
    char*    get_specialization ( void );

    bool check_doctor_data();

    friend bool operator< (Doctor doc1, Doctor doc2);
    friend bool operator> (Doctor doc1, Doctor doc2);
    friend bool operator==(Doctor doc1, Doctor doc2);

    friend std::ostream&  operator<< (std::ostream&  out,  Doctor &obj);
};


