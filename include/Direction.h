#pragma once
#include <iostream>
#include ".\..\include\Patient.h"
#include ".\..\include\Doctor.h"
#include ".\..\include\Date.h"
using namespace std;


class Direction
{
private:
    Doctor  *doctor_ptr;
    Patient *patient_ptr;
    Date direction_date;
    Time direction_time;

public:
    Direction(Doctor *doctor, Patient *patient, Date date, Time time);

    void set_doctor         ( Doctor  element );
    void set_patient        ( Patient element );
    void set_direction_date ( Date    element );
    void set_direction_time ( Time    element );

    Doctor  get_doctor         ( void );
    Patient get_patient        ( void );
    Date    get_direction_date ( void );
    Time    get_direction_time ( void );

    friend std::ostream&  operator<< (std::ostream&  out,  Direction &obj);
};

