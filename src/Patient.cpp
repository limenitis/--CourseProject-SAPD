#include ".\..\include\Patient.h"
#include ".\..\include\SimpleLogs.h"
#include ".\..\include\str-tools.h"

Patient::Patient()
{
    log_warning("Patient", "Patient", "constructor work " << this)

    patient_name = "";
    work_place = "";
    addres = "";
    year_born = 0;
}

Patient::Patient(const Patient &obj)
{
    log_warning("Patient", "Patient", "copy constructor work ");
    log_warning("Patient", "Patient", "copy from " << &obj);
    log_warning("Patient", "Patient", "copy to   " << this)

    this->reg_num      = obj.reg_num;
    this->patient_name = obj.patient_name;
    this->work_place   = obj.work_place;
    this->addres       = obj.addres;
    this->year_born    = obj.year_born;
}


Patient::~Patient()
{
    log_warning("Patient", "Patient", "destructor work " << this)
}

void Patient::set_reg (int area_number, int serial_number)
{
    reg_num.set_reg(area_number, serial_number);
}

void Patient::set_reg (string reg)
{
    reg_num.set_reg(reg);
}

void Patient::set_reg (const RegistrationNumber &reg)
{
    reg_num = reg;
}

void Patient::set_name (string str)
{
    this->patient_name = str;
}

void Patient::set_work (string str)
{
    this->work_place = str;
}

void Patient::set_addres (string str)
{
    this->addres = str;
}

void Patient::set_year_born (int val)
{
    year_born = val;
}

bool Patient::check_patient_data()
{
    if (year_born > 1000)   { return true;  }
    else                    { return false; }
}

RegistrationNumber* Patient::get_reg ( void )
{
     return &reg_num;
}

string Patient::get_name ( void )
{
    return patient_name;
}

string Patient::get_work ( void )
{
    return work_place;
}

string Patient::get_addres ( void )
{
    return addres;
}

int Patient::get_year_born ( void )
{
    return year_born;
}


std::ostream&  operator<< (std::ostream&  out,  Patient &obj)
{
    return out;
}

std::istream&  operator>> (std::istream&  in,   Patient &obj)
{

    cout << "Patient name : " << endl;
    in >> obj.patient_name;
    cout << "Work place   : " << endl;
    in >> obj.work_place;
    cout << "Addres       : " << endl;
    in >> obj.addres;
    cout << "Year born    : " << endl;
    in >> obj.year_born;
    cout << "Registration number : " << endl;
    in >> obj.reg_num;

    return in;
}
