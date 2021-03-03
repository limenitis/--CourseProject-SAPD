#pragma once
#include ".\..\headers\RegistrationNumber.h"

class Patient
{
protected:
    RegistrationNumber reg_num;
    string patient_name;
    string work_place;
    string addres;
    int year_born;

public:
    Patient();
    Patient(const Patient &obj);
    ~Patient();

    void set_reg       (int area_number, int serial_number);
    void set_reg       (string reg);
    void set_reg       (const RegistrationNumber &reg);
    void set_name      (string patient_name);
    void set_work      (string work_place);
    void set_addres    (string addres);
    void set_year_born (int year_born);

    RegistrationNumber *get_reg   ( void );
    string get_name      ( void );
    string get_work      ( void );
    string get_addres    ( void );
    int   get_year_born ( void );

    bool check_patient_data();

    friend std::ostream&  operator<< (std::ostream&  out,  Patient &obj);
    friend std::istream&  operator>> (std::istream&  in,   Patient &obj);
};

