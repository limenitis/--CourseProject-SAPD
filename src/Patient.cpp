#include ".\..\include\Patient.h"
#include ".\..\include\SimpleLogs.h"
#include ".\..\include\str-tools.h"

Patient::Patient()
{
    log_warning("Patient", "Patient", "constructor work " << this)

    reg_num = new RegistrationNumber;
    patient_name = new char[100];
    patient_name[100-1] = '\0';
    work_place = new char[100];
    work_place[100-1] = '\0';
    addres = new char[120];
    addres[120-1] = '\0';
    year_born = 0;
}

Patient::Patient(const Patient &obj)
{
    log_warning("Patient", "Patient", "copy constructor work ");
    log_warning("Patient", "Patient", "copy from " << &obj);
    log_warning("Patient", "Patient", "copy to   " << this)

    this->reg_num = new RegistrationNumber{ *obj.reg_num };

    int len_patient_name = len_str(obj.patient_name);
    int len_work_place = len_str(obj.work_place);
    int len_addres = len_str(obj.addres);

    this->patient_name = new char[len_patient_name];
    this->work_place = new char[len_work_place];
    this->addres = new char[len_addres];

    for(int i = 0; i < len_patient_name; i++)
    {
        this->patient_name[i] = obj.patient_name[i];
    }
    this->patient_name[len_patient_name-1] = '\0';

    for(int i = 0; i < len_work_place; i++)
    {
        this->work_place[i] = obj.work_place[i];
    }
    this->work_place[len_work_place-1] = '\0';

    for(int i = 0; i < len_addres; i++)
    {
        this->addres[i] = obj.addres[i];
    }
    this->addres[len_addres-1] = '\0';

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
