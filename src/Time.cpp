#include ".\..\include\Time.h"

using namespace std;

char* Time::convert_int2str(int hour, int minute)
{}

void Time::convert_str2int(char str[6])
{}

Time::Time()
{}

Time::Time(char str[6])
{}

Time::Time(int hour, int minute)
{}

void Time::set_time(int hour, int minute)
{}

void Time::set_time(char str[6])
{}

char* Time::get_time()
{}

bool Time::check_time()
{}

bool operator< (Time t1, Time t2)
{
    if (t1.hour < t2.hour)
    {
        return true;
    }
    else if (t1.hour == t2.hour)
    {
        if (t1.minute < t2.minute)
        {
            return true;
        }
        else
        {
            return false;
        }        
    }
    else
    {
        return false;
    }
}
bool operator> (Time t1, Time t2)
{
    if (t1.hour > t2.hour)
    {
        return true;
    }
    else if (t1.hour == t2.hour)
    {
        if (t1.minute > t2.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator<=(Time t1, Time t2)
{
    if(t1.hour == t2.hour && t1.minute == t2.minute)
    {
        return true;
    }

    if (t1.hour <= t2.hour)
    {
        return true;
    }
    else if (t1.hour == t2.hour)
    {
        if (t1.minute <= t2.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator>=(Time t1, Time t2)
{
    if (t1.hour == t2.hour && t1.minute == t2.minute)
    {
        return true;
    }

    if (t1.hour >= t2.hour)
    {
        return true;
    }
    else if (t1.hour == t2.hour)
    {
        if (t1.minute >= t2.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


std::ostream& operator<< (std::ostream& out, Time &obj)
{}

std::istream& operator>> (std::istream& in,  Time &obj)
{}





// std::ostream  &operator<<(std::ostream &out,   Time &t)
// {
//     convert_time(t);
//     out << t.str;

//     return out;
// }

// std::istream  &operator>>(std::istream &in,    Time &t)
// {
//     cout << "hour   : "; in >> t.hour;
//     cout << "minute : "; in >> t.minute;
//     cout << "second : "; in >> t.second;
//     convert_time(t);
//     return in;
// }

// std::ofstream &operator<<(std::ofstream &fout, Time &t)
// {
//     fout << t.str;

//     return fout;
// }

// std::ifstream &operator>>(std::ifstream &fin,  Time &t)
// {
//     char symbol = ' ';
//     char tmp[2] = {' ', ' '};

//     fin >> tmp[0];
//     fin >> tmp[1];
//     t.hour   = char2int(tmp[0])*10 + char2int(tmp[1]);
//     fin >> symbol; // get ':'
//     fin >> tmp[0];
//     fin >> tmp[1];
//     t.minute = char2int(tmp[0])*10 + char2int(tmp[1]);
//     fin >> symbol; // get ':'
//     fin >> tmp[0];
//     fin >> tmp[1];
//     t.second = char2int(tmp[0])*10 + char2int(tmp[1]);
//     convert_time(t);
//     return fin;
// }

// void convert_time(Time &t)
// {
//     // ints to str
//     char temp[2] = {'0','0'};
//     if(t.hour / 10 == 0) // one-digit number
//     {
//         temp[0] = '0';
//         temp[1] = num2char(t.hour);
//     }
//     else // two-digit number
//     {
//         temp[0] = num2char(t.hour / 10);
//         temp[1] = num2char(t.hour % 10);
//     }

//     t.str[0] = temp[0];
//     t.str[1] = temp[1];

//     if(t.minute / 10 == 0)
//     {
//         temp[0] = '0';
//         temp[1] = num2char(t.minute);
//     }
//     else
//     {
//         temp[0] = num2char(t.minute / 10);
//         temp[1] = num2char(t.minute % 10);
//     }

//     t.str[3] = temp[0];
//     t.str[4] = temp[1];

//     if(t.second / 10 == 0)
//     {
//         temp[0] = '0';
//         temp[1] = num2char(t.second);
//     }
//     else
//     {
//         temp[0] = num2char(t.second / 10);
//         temp[1] = num2char(t.second % 10);
//     }

//     t.str[6] = temp[0];
//     t.str[7] = temp[1];
// }
