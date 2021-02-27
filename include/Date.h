#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    // format date: 00.00.0000
    string date_str;
    int day;
    int month;
    int year;

    string convert_int2str(int day, int month, int year);
    void convert_str2int(string str);

public:
    Date();
    ~Date();
    Date(string str);
    Date(int day, int month, int year);

    void  set_date(int day, int month, int year);
    void  set_date(string str);
    string get_date();
    bool  check_date();

    friend std::ostream&  operator<< (std::ostream&  out,  Date &obj);
    friend std::istream&  operator>> (std::istream&  in,   Date &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Date &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Date &obj);
};
