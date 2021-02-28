#pragma once
// #include ".\..\include\Time.h"
// #include ".\..\include\Date.h"
// #include ".\..\include\Schedule.h"
// #include ".\..\include\RegistrationNumber.h"
#include ".\..\include\HashTable.h"
// #include ".\..\include\LinkedList.h"
#include ".\..\include\AVLTree.h"
// #include ".\..\include\str-tools.h"

#include ".\..\include\Doctor.h"
#include ".\..\include\Patient.h"
#include ".\..\include\Direction.h"

#include <iostream>
// #include <fstream>
using namespace std;


class Hospital{
private:
    HashTable* table;

public:
    Hospital();
    ~Hospital();

    bool insert_patient ( void );
    bool remove_patient ( void );
    void print_patient  ( void );
    void print_patients ( void );
    bool clear_patients ( void );
    bool find_patient_by_name    ( void );
    bool find_patient_by_reg_num ( void );


    bool add_doctor    ( void );
    bool remove_doctor ( void );
    void print_doctor  ( void );
    void print_doctors ( void );
    bool clear_doctors ( void );
    bool find_doctor_by_name ( void );
    bool find_doctor_by_post ( void );

    bool add_direction    ( void ); 
    bool return_direction ( void );

};

