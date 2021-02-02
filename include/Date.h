#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    // format date: char str[11] = {'0', '0', '.', '0', '0', '.', '0', '0', '0', '0', '\0'};
    int day;
    int month;
    int year;

    char* convert_int2str(int day, int month, int year);
    void convert_str2int(char str[11]);

public:
    Date();
    Date(char str[11]);
    Date(int day, int month, int year);

    void  set_date(int day, int month, int year);
    void  set_date(char str[11]);
    char* get_date();
    bool  check_date();

    friend std::ostream&  operator<< (std::ostream&  out,  Date &obj);
    friend std::istream&  operator>> (std::istream&  in,   Date &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Date &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Date &obj);
};
