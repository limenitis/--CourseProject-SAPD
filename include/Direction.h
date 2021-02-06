#pragma once
#include <iostream>
#include ".\..\include\Patient.h"
#include ".\..\include\Doctor.h"
#include ".\..\include\Date.h"
using namespace std;


class Direction : private Patient, private Doctor 
{
private:
    Doctor  *doctor_ptr;
    Patient *patient_ptr;
    Date direction_date;
    Time direction_time;

public:
    Direction(Doctor *doctor, Patient *patient, Date date, Time time);

    void get_data(RegistrationNumber num, char doctor_name[25], Date date, Time time);

    friend std::ostream&  operator<< (std::ostream&  out,  Direction &obj);
    friend std::istream&  operator>> (std::istream&  in,   Direction &obj);
};

