#pragma once
#include ".\..\include\RegistrationNumber.h"

class Patient
{
protected:
    RegistrationNumber reg_num;
    char patient_name[100] = {'\0'};
    char work_place[100] = {'\0'};
    char addres[120] = {'\0'};
    int  year_born;

public:
    Patient();

    void set_reg_num   (int area_number, int serial_number);
    void set_name      (char* patient_name);
    void set_work      (char* work_place);
    void set_addres    (char* addres);
    void set_year_born (int year_born);

    bool check_patient_data();
};

