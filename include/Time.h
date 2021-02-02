#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
    // format time: char str[6] = {'0','0',':','0','0','\0'};
    int hour;
    int minute;

    char* convert_int2str(int hour, int minute);
    void convert_str2int(char str[6]);

public:
    Time();
    Time(char str[6]);
    Time(int hour, int minute);

    void  set_time(int hour, int minute);
    void  set_time(char str[6]);
    char* get_time();
    bool  check_time();

    friend bool operator< (Time t1, Time t2);
    friend bool operator> (Time t1, Time t2);
    friend bool operator<=(Time t1, Time t2);
    friend bool operator>=(Time t1, Time t2);

    friend std::ostream&  operator<< (std::ostream&  out,  Time &obj);
    friend std::istream&  operator>> (std::istream&  in,   Time &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Time &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Time &obj);
};
