#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
    // format time: 00:00
    string time_str;
    int  hour;
    int  minute;

    string convert_int2str(int hour, int minute);
    void convert_str2int(string str); 

public:
    Time();
    ~Time();
    Time(string str);
    Time(int hour, int minute);

    void  set_time(int hour, int minute);
    void  set_time(string str);
    string get_time();
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
