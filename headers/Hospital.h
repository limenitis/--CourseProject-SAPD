#pragma once
// #include ".\..\include\Time.h"
// #include ".\..\include\Date.h"
// #include ".\..\include\Schedule.h"
// #include ".\..\include\RegistrationNumber.h"
// #include ".\..\include\str-tools.h"

#include ".\..\headers\HashTable.h"
#include ".\..\headers\LinkedList.h"
#include ".\..\headers\AVLTree.h"

#include ".\..\headers\Doctor.h"
#include ".\..\headers\Patient.h"
#include ".\..\headers\Direction.h"

#include <iostream>
// #include <fstream>
using namespace std;


class Hospital{
private:
    HashTable* table;
    AVLTree* tree;
    // LinkedList* list;

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


    bool insert_doctor    ( void );
    bool remove_doctor ( void );
    void print_doctor  ( void );
    void print_doctors ( void );
    bool clear_doctors ( void );
    void print_doctors_tree  ( void );
    bool find_doctor_by_name ( void );
    bool find_doctor_by_post ( void );

    bool add_direction    ( void ); 
    bool return_direction ( void );

};

