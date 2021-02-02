#include ".\..\include\Date.h"

using namespace std;

char* Date::convert_int2str(int day, int month, int year)
{}

void Date::convert_str2int(char str[11])
{}

Date::Date()
{}

Date::Date(char str[11])
{}

Date::Date(int day, int month, int year)
{}

void Date::set_date(int day, int month, int year)
{}

void Date::set_date(char str[11])
{}

char* Date::get_date()
{}

bool Date::check_date()
{}

std::ostream& operator<< (std::ostream& out, Date &obj)
{}

std::istream& operator>> (std::istream& in, Date &obj)
{}


