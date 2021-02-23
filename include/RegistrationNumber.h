#pragma once
#include <iostream>
using namespace std;

class RegistrationNumber
{
private:
    // format reg: char str[11] = {'1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0'};

    char *reg_str;
    int area_number;
    int serial_number;

    char* convert_int2str(int area_number, int serial_number);
    void convert_str2int(char str[11]);

public:
    RegistrationNumber();
    ~RegistrationNumber();
    RegistrationNumber(char str[11]);
    RegistrationNumber(int area_number, int serial_number);
    RegistrationNumber(const RegistrationNumber &obj);

    void  set_reg(int area_number, int serial_number);
    void  set_reg(char str[11]);
    char* get_reg();
    bool  check_reg();

    friend std::ostream&  operator<< (std::ostream&  out,  RegistrationNumber &obj);
    friend std::istream&  operator>> (std::istream&  in,   RegistrationNumber &obj);
};
