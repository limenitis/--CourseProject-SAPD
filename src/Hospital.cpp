#include ".\..\include\Hospital.h"

Hospital::Hospital()
{
    table = new HashTable;
}

Hospital::~Hospital()
{
    delete table;
}

bool Hospital::insert_patient()
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
    //new_patient.set_reg(new_reg);
    new_patient.set_reg(new_reg.get_reg());

    HashTableNode element;
    element.intsert(new_patient);

    return table->remove(element);
}

void Hospital::print_patient  ( void )
{
    int id;
    cout << "id : " << endl;
    cin >> id;
    table->print(id);
}

void Hospital::print_patients  ( void )
{
    table->print();
}

bool Hospital::clear_patients  ( void )
{
    table->clear();
    return true;
}

bool Hospital::find_patient_by_name ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::find_patient_by_reg_num ( void )
{
    RegistrationNumber new_reg;
    cin >> new_reg;

    Patient new_patient;
    //new_patient.set_reg(new_reg);
    new_patient.set_reg(new_reg.get_reg());

    HashTableNode element;
    element.intsert(new_patient);

    int result = table->find_key(element);

    if (result != -1)
    {
        table->print(result, result+1);
        return true;
    }
    else
    {
        return false;
    }
}

bool Hospital::add_doctor ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::remove_doctor ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::edit_doctor ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

void Hospital::print_doctors  ( void )
{
    cout << "Empty implementation" << endl;
}

bool Hospital::clear_doctors  ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::find_doctor_by_name ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::find_doctor_by_post ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::add_direction ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

bool Hospital::return_direction ( void )
{
    cout << "Empty implementation" << endl;
    return true;
}

