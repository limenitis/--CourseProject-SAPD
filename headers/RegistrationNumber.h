#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class RegistrationNumber
{
private:
    // format reg: 00-0000000
    string reg_str;
    int area_number;
    int serial_number;

    string convert_int2str(int area_number, int serial_number);
    void   convert_str2int(string str);

public:
    RegistrationNumber();
    ~RegistrationNumber();
    RegistrationNumber(string str);
    RegistrationNumber(int area_number, int serial_number);
    RegistrationNumber(const RegistrationNumber &obj);

    void   set_reg(int area_number, int serial_number);
    void   set_reg(string str);
    string get_reg();
    bool   check_reg();

    friend std::ostream&  operator<< (std::ostream&  out,  RegistrationNumber &obj);
    friend std::istream&  operator>> (std::istream&  in,   RegistrationNumber &obj);
};
