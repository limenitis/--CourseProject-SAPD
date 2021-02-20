#include ".\..\include\Schedule.h"
#include ".\..\include\Time.h"
#include ".\..\include\str-tools.h"

char* Schedule::convert_int2str(Time start_time, Time finish_time)
{
    char *time1 = start_time.get_time();
    char *time2 = finish_time.get_time();

    int i = 0;
    while (time1[i] != '\0')
    {
        schedule_str[i] = time1[i];
        i++;
    }

    schedule_str[i] = '-';
    i++;

    while (time2[i-6] != '\0')
    {
        schedule_str[i] = time2[i-6];
        i++;
    }

    return schedule_str;
}

void  Schedule::convert_str2int(char str[12])
{
    char *str1 = new char[6]{'\0'};
    char *str2 = new char[6]{'\0'};

    int i = 0;
    while (str[i] != '-')
    {
        str1[i] = str[i];
        i++;
    }
    i++;
    while (str[i] != '\0')
    {
        str2[i-6] = str[i];
        i++;
    }

    start_time.set_time(str1);
    finish_time.set_time(str2);

    delete[] str1;
    delete[] str2;   
}

Schedule::Schedule()
{
    // Time constructors work
}

Schedule::Schedule(char str[12])
{
    convert_str2int(str);
}

Schedule::Schedule(Time s, Time f)
{
    this->set_schedule(s, f);
}

void  Schedule::set_schedule(Time s, Time f)
{
    if(s < f)
    {
        start_time = s;
        finish_time = f;
    }
    else
    {
        // default time : 00:00
    }
}

void  Schedule::set_schedule(char str[12])
{
    convert_str2int(str);
}

char* Schedule::get_schedule()
{
    return convert_int2str(start_time, finish_time);
}

bool  Schedule::check_schedule()
{
    return start_time.check_time() && finish_time.check_time() && (start_time < finish_time);
}

std::ostream&  operator<< (std::ostream&  out,  Schedule &obj)
{
    char* str = obj.convert_int2str(obj.start_time, obj.finish_time);

    int i = 0;
    while (str[i] != '\0')
    {
        out << str[i];
        i++;
    }
   
    return out;
}

std::istream&  operator>> (std::istream&  in,   Schedule &obj)
{
    Time t1;
    Time t2;

    cout << "start_time  : "; in >> t1;
    cout << "finish_time : "; in >> t2;

    obj.set_schedule(t1, t2);

    return in;
}

