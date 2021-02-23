#include ".\..\include\Patient.h"
#include ".\..\include\SimpleLogs.h"

Patient::Patient()
{
    log_warning("Patient", "Patient", "constructor work " << this)

    reg_num = new RegistrationNumber;
    patient_name = new char[100]{ '\0' };
    work_place = new char[100]{ '\0' };
    addres = new char[120]{ '\0' };
    year_born = 0;
}

Patient::Patient(const Patient &obj)
{
    log_warning("Patient", "Patient", "copy constructor work ");
    log_warning("Patient", "Patient", "copy from " << &obj);
    log_warning("Patient", "Patient", "copy to   " << this)

    this->reg_num = new RegistrationNumber{ *obj.reg_num };
    this->patient_name = new char[100]{*obj.patient_name};
    this->work_place = new char[100]{*obj.work_place};
    this->addres = new char[120]{*obj.addres};
    this->year_born = obj.year_born;
}


Patient::~Patient()
{
    log_warning("Patient", "Patient", "destructor work " << this)

    delete reg_num;
    delete[] patient_name;
    delete[] work_place;
    delete[] addres;
}

void Patient::set_reg (int area_number, int serial_number)
{
    reg_num->set_reg(area_number, serial_number);
}

void Patient::set_reg (char* reg)
{
    reg_num->set_reg(reg);
}

void Patient::set_reg (const RegistrationNumber &reg)
{
    delete reg_num;
    reg_num = new RegistrationNumber{ reg };
}

void Patient::set_name (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        patient_name[i] = str[i];
    }
    patient_name[i] = '\0';
}

void Patient::set_work (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        work_place[i] = str[i];
    }
    work_place[i] = '\0';
}

void Patient::set_addres (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        addres[i] = str[i];
    }
    addres[i] = '\0';
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
     return reg_num;
}

char* Patient::get_name ( void )
{
    return patient_name;
}

char* Patient::get_work ( void )
{
    return work_place;
}

char* Patient::get_addres ( void )
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
    in >> *obj.reg_num;

    return in;
}
