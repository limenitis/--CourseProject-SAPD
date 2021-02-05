#pragma once
#include ".\..\include\Time.h"

#include <iostream>
using namespace std;

class Schedule
{
private:
    // format Schedule: char str[12] = {'1', '0', ':', '0', '0', '-', '1', '8', ':', '0', '0', '\0'};
    Time start_time;
    Time finish_time;

    char* convert_int2str(Time start_time, Time finish_time);
    void convert_str2int(char str[12]);

public:
    Schedule();
    Schedule(char str[12]);
    Schedule(Time start_time, Time finish_time);

    void  set_schedule(Time start_time, Time finish_time);
    void  set_schedule(char str[12]);
    char* get_schedule();
    bool  check_schedule();

    friend std::ostream&  operator<< (std::ostream&  out,  Schedule &obj);
    friend std::istream&  operator>> (std::istream&  in,   Schedule &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Schedule &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Schedule &obj);
};
