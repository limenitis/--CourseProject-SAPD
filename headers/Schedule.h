#pragma once
#include ".\..\headers\Time.h"

#include <iostream>
using namespace std;

class Schedule
{
private:
    // format Schedule: 10:00-18:00
    string schedule_str = "00:00-00:00";
    Time start_time;
    Time finish_time;

    string convert_int2str(Time start_time, Time finish_time);
    void   convert_str2int(string str);

public:
    Schedule();
    ~Schedule();
    Schedule(string str);
    Schedule(Time start_time, Time finish_time);

    void  set_schedule(Time start_time, Time finish_time);
    void  set_schedule(string str);
    string get_schedule();
    bool  check_schedule();

    friend std::ostream&  operator<< (std::ostream&  out,  Schedule &obj);
    friend std::istream&  operator>> (std::istream&  in,   Schedule &obj);
};
