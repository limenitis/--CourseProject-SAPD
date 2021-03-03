#include ".\..\headers\Doctor.h"
#include ".\..\headers\str-tools.h"
#include ".\..\headers\SimpleLogs.h"

using namespace std;

Doctor::Doctor()
{
    cabinet_number = 0;
}

Doctor::~Doctor()
{
    log_warning("Doctor", "~Doctor", "destruct work");
}

void Doctor::set_schedule(Time start_time, Time finish_time)
{
    schedule.set_schedule(start_time, finish_time);
}

void Doctor::set_schedule(string str)
{
    schedule.set_schedule(str);
}

void Doctor::set_cabinet_number(int number)
{
    if (cabinet_number > 0) { cabinet_number = number; }
    else                    { cabinet_number = 0; }
}

void Doctor::set_doctor_name(string str)
{
    if(str.size() < 26)
    {
        this->doctor_name = str;
    }
}

void Doctor::set_specialization(string str)
{
    this->specialization = str;
}

bool Doctor::check_doctor_data()
{
    if (cabinet_number > 0 && schedule.check_schedule()) { return true;  }
    else                                                 { return false; }
}

Schedule Doctor::get_schedule ( void )
{
    return schedule;
}

int Doctor::get_cabinet_number ( void )
{
    return cabinet_number;
}

string Doctor::get_doctor_name ( void )
{
    return doctor_name;
}

string Doctor::get_specialization ( void )
{
    return specialization;
}

bool operator< (Doctor doc1, Doctor doc2)
{
    int i = 0;
    while ( doc1.doctor_name.size() > i && doc2.doctor_name.size() > i )
    {
        if (doc1.doctor_name[i] < doc2.doctor_name[i])
        {
            return true;
        }
        else if (doc1.doctor_name[i] > doc2.doctor_name[i])
        {
            return false;
        }
    }
    return false;
}

bool operator> (Doctor doc1, Doctor doc2)
{
    int i = 0;
    while ( doc1.doctor_name.size() > i && doc2.doctor_name.size() > i )
    {
        if (doc1.doctor_name[i] > doc2.doctor_name[i])
        {
            return true;
        }
        else if (doc1.doctor_name[i] < doc2.doctor_name[i])
        {
            return false;
        }
    }
    return false;
}

bool operator==(Doctor doc1, Doctor doc2)
{
    if ( doc1.doctor_name.size() != doc2.doctor_name.size() )
    {
        return false;
    }

    int i = doc1.doctor_name.size();
    while (i--)
    {
        if (doc1.doctor_name[i] != doc2.doctor_name[i])
        {
            return false;
        }
    }
    return true;
}

std::ostream&  operator<< (std::ostream&  out,  Doctor &obj)
{
    cout << obj.doctor_name;

    return out;
}

std::istream&  operator>> (std::istream&  in,   Doctor &obj)
{
    cout << "Doctor name" << endl;
    cin >> obj.doctor_name;
    cout << "Specialization" << endl;
    cin >> obj.specialization;
    cout << "Cabinet number" << endl;
    cin >> obj.cabinet_number;
    cout << "Schedule" << endl;
    cin >> obj.schedule;

    return in;
}

