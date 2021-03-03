#pragma once
#include ".\..\headers\Schedule.h"

class Doctor
{
protected:
    Schedule schedule;
    int cabinet_number;
    string doctor_name;
    string specialization; 

public:
    Doctor();
    ~Doctor();

    void set_schedule       (Time start_time, Time finish_time);
    void set_schedule       (string str);
    void set_cabinet_number (int number);
    void set_doctor_name    (string name);
    void set_specialization (string spec);

    Schedule get_schedule       ( void );
    int      get_cabinet_number ( void );
    string   get_doctor_name    ( void );
    string   get_specialization ( void );

    bool check_doctor_data();

    friend bool operator< (Doctor doc1, Doctor doc2);
    friend bool operator> (Doctor doc1, Doctor doc2);
    friend bool operator==(Doctor doc1, Doctor doc2);

    friend std::ostream&  operator<< (std::ostream&  out,  Doctor &obj);
    friend std::istream&  operator>> (std::istream&  in,   Doctor &obj);
};


