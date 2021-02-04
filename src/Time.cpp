#pragma once
#include ".\..\include\Time.h"
#include ".\..\include\str-tools.h"

using namespace std;

char* Time::convert_int2str(int hour, int minute)
{
    if(hour / 10 == 0) // one-digit number
    {
        time_str[0] = '0';
        time_str[1] = int2char(hour);
    }
    else // two-digit number
    {
        time_str[0] = int2char(hour / 10);
        time_str[1] = int2char(hour % 10);
    }

    time_str[2] = ':';

    if(minute / 10 == 0)
    {
        time_str[3] = '0';
        time_str[4] = int2char(minute);
    }
    else
    {
        time_str[3] = int2char(minute / 10);
        time_str[4] = int2char(minute % 10);
    }

    return time_str;
}

void Time::convert_str2int(char str[6])
{
    hour   = char2int(str[0]) * 10 + char2int(str[1]);
    minute = char2int(str[3]) * 10 + char2int(str[4]);
}

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(char str[6])
{
    convert_str2int(str);
}

Time::Time(int h, int m)
{
    hour = h;
    minute = m;
}

Time::~Time()
{
    delete[] time_str;
}

void Time::set_time(int h, int m)
{
    if ( (0 <= h) && (h < 60) ) { hour = h; }
    else                        { hour = 0; }

    if ( (0 <= m) && (m < 60) ) { minute = h; }
    else                        { minute = 0; }
}

void Time::set_time(char str[6])
{
    convert_str2int(str);
}

char* Time::get_time()
{
    return convert_int2str(hour, minute);
}

bool Time::check_time()
{
    if ( 0 <= hour && hour < 60 && 0 <= minute && minute < 60 ) { return true; }
    else { return false; }
}

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
{
    char* str = obj.convert_int2str(obj.hour, obj.minute);

    int i = 0;
    while (str[i] != '\0')
    {
        out << str[i];
        i++;
    }
   
    return out;
}

std::istream& operator>> (std::istream& in,  Time &obj)
{
    cout << "hour   : "; in >> obj.hour;
    cout << "minute : "; in >> obj.minute;
    return in;
}

