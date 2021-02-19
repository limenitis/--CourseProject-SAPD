#include ".\..\include\Date.h"
#include ".\..\include\str-tools.h"

using namespace std;

char* Date::convert_int2str(int day, int month, int year)
{
    if (day / 10 == 0) // one-digit number
    {
        date_str[0] = '0';
        date_str[1] = int2char(day);
    }
    else // two-digit number
    {
        date_str[0] = int2char(day / 10);
        date_str[1] = int2char(day % 10);
    }

    date_str[2] = '.';

    if (month / 10 == 0) // one-digit number
    {
        date_str[3] = '0';
        date_str[4] = int2char(month);
    }
    else // two-digit number
    {
        date_str[3] = int2char(month / 10);
        date_str[4] = int2char(month % 10);
    }

    date_str[5] = '.';

    date_str[6] = int2char(year / 1000 % 10 );
    date_str[7] = int2char(year / 100  % 10 );
    date_str[8] = int2char(year / 10   % 10 );
    date_str[9] = int2char(year / 1    % 10 );

    return date_str;
}

void Date::convert_str2int(char str[11])
{
    day   = char2int(str[0]) * 10 + char2int(str[1]);
    month = char2int(str[3]) * 10 + char2int(str[4]);

    year  = char2int(str[6]) * 1000 + 
            char2int(str[7]) * 100  + 
            char2int(str[8]) * 10   + 
            char2int(str[9]);
}

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(char str[11])
{
    convert_str2int(str);
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

Date::~Date()
{
    delete[] date_str;
}

bool isleap(int year) { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }

void Date::set_date(int d, int m, int y)
{
    int maxdays[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( 1 <= y ){ year = y;    }
    else         { year = 0; }

    if ( isleap(year) ) { maxdays[2] = 29; }

    if ( (1 <= m) && (m <= 12) ) { month = m; }
    else                         { month = 0; }

    if ( (1 <= d) && (d <= maxdays[month]) ){ day = d; }
    else                                    { day = 0; }
}

void Date::set_date(char str[11])
{
    convert_str2int(str);
}

char* Date::get_date()
{
    return convert_int2str(day, month, year);
}

bool Date::check_date()
{
    int maxdays[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool good_year;
    bool good_month;
    bool good_day;

    if ( 1 <= year ) { good_year = true;  }
    else             { good_year = false; }

    if ( isleap(year) ) { maxdays[2] = 29; }

    if ( (1 <= month) && (month <= 12) ) { good_month = true;  }
    else                                 { good_month = false; }

    if ( (1 <= day) && (day <= maxdays[month]) ) { good_day = true;  }
    else                                         { good_day = false; }

    return good_day && good_month && good_year;
}

std::ostream& operator<< (std::ostream& out, Date &obj)
{
    char *str = obj.convert_int2str(obj.day, obj.month, obj.year);

    int i = 0;
    while(str[i] != '\0')
    {
        out << str[i];
        i++;
    }

    return out;
}

std::istream& operator>> (std::istream& in, Date &obj)
{
    cout << "day   : "; in >> obj.day;
    cout << "month : "; in >> obj.month;
    cout << "year  : "; in >> obj.year;
    return in;
}


