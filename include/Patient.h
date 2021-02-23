#pragma once
#include ".\..\include\RegistrationNumber.h"

class Patient
{
protected:
    RegistrationNumber* reg_num;
    char* patient_name;
    char* work_place;
    char* addres;
    int year_born;

public:
    Patient();
    Patient(const Patient &obj);
    ~Patient();

    void set_reg       (int area_number, int serial_number);
    void set_reg       (char* reg);
    void set_reg       (const RegistrationNumber &reg);
    void set_name      (char* patient_name);
    void set_work      (char* work_place);
    void set_addres    (char* addres);
    void set_year_born (int year_born);

    RegistrationNumber* get_reg   ( void );
    char* get_name      ( void );
    char* get_work      ( void );
    char* get_addres    ( void );
    int   get_year_born ( void );

    bool check_patient_data();

    friend std::ostream&  operator<< (std::ostream&  out,  Patient &obj);
    friend std::istream&  operator>> (std::istream&  in,   Patient &obj);
};

