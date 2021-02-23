#include ".\..\include\Direction.h"
using namespace std;


Direction::Direction(Doctor *doc, Patient *pat, Date date, Time time)
{
    doctor_ptr = doc;
    patient_ptr = pat;
    direction_date = date;
    direction_time = time;
}

void Direction::set_data(Doctor *doc, Patient *pat, Date date, Time time)
{
    doctor_ptr = doc;
    patient_ptr = pat;
    direction_date = date;
    direction_time = time;
}

void Direction::get_data(RegistrationNumber& num, char* doctor_name, Date& date, Time& time)
{
    num = *patient_ptr->get_reg();
    doctor_name = doctor_ptr->get_doctor_name();
    date = direction_date.get_date();
    time = direction_time.get_time();
}

std::ostream&  operator<< (std::ostream&  out,  Direction &obj)
{
    out << obj.doctor_ptr     << " -|- ";
    out << obj.patient_ptr    << "  \n ";
    out << obj.direction_date << " -|- ";
    out << obj.direction_time << "  \n ";

    return out;
}

