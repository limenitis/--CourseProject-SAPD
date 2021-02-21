#include ".\..\include\Hospital.h"

Hospital::Hospital()
{}

Hospital::~Hospital()
{
    delete table;
}

bool Hospital::add_patient ()
{
    Patient new_patient;
    cin >> new_patient;

    HashTableNode element;
    element.intsert(new_patient);

    return table->insert(element);
}

bool Hospital::remove_patient ()
{
    RegistrationNumber new_reg;
    cin >> new_reg;

    Patient new_patient;
    new_patient.set_reg(new_reg);

    HashTableNode element;
    element.intsert(new_patient);

    return table->remove(element);
}

bool Hospital::edit_patient ()
{
    return true;
}

void Hospital::print_patients  ( void )
{
    table->print();
}

bool Hospital::clear_patients  ( void )
{
    return true;
}

bool Hospital::find_patient_by_name ()
{
    return true;
}

bool Hospital::find_patient_by_reg_num ()
{
    return true;
}

bool Hospital::add_doctor ()
{
    return true;
}

bool Hospital::remove_doctor ()
{
    return true;
}

bool Hospital::edit_doctor ()
{
    return true;
}

void Hospital::print_doctors  ( void )
{}

bool Hospital::clear_doctors  ( void )
{
    return true;
}

bool Hospital::find_doctor_by_name ()
{
    return true;
}

bool Hospital::find_doctor_by_post ()
{
    return true;
}

bool Hospital::add_direction ()
{
    return true;
}

bool Hospital::return_direction ()
{
    return true;
}

