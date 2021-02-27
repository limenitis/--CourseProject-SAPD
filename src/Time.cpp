#include ".\..\include\Time.h"
#include ".\..\include\str-tools.h"
#include ".\..\include\SimpleLogs.h"

using namespace std;

string Time::convert_int2str(int hour, int minute)
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

void Time::convert_str2int(string str)
{
    int h = char2int(str[0]) * 10 + char2int(str[1]);
    int m = char2int(str[3]) * 10 + char2int(str[4]);

    this->set_time(h, m);
}

Time::Time()
{
    this->time_str = "00:00";
    this->set_time(0, 0);
}

Time::Time(string str)
{
    this->time_str = "00:00";
    convert_str2int(str);
}

Time::Time(int h, int m)
{
    this->time_str = "00:00";
    this->set_time(h, m);
}

Time::~Time()
{
    log_warning("Time", "~Time", "destruct work");
}

void Time::set_time(int h, int m)
{
    if ( (0 <= h) && (h < 24) ) { hour = h; }
    else                        { hour = 0; }

    if ( (0 <= m) && (m < 60) ) { minute = m; }
    else                        { minute = 0; }
}

void Time::set_time(string str)
{
    convert_str2int(str);
}

string Time::get_time()
{
    return convert_int2str(hour, minute);
}

bool Time::check_time()
{
    if ( 0 <= hour && hour < 24 && 0 <= minute && minute < 60 ) { return true; }
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
    out << obj.convert_int2str(obj.hour, obj.minute);
   
    return out;
}

std::istream& operator>> (std::istream& in,  Time &obj)
{
    int h, m;

    cout << "hour   : "; in >> h;
    cout << "minute : "; in >> m;

    obj.set_time(h, m);

    return in;
}

