#include ".\..\include\RegistrationNumber.h"
#include ".\..\include\SimpleLogs.h"
#include ".\..\include\str-tools.h"

using namespace std;

char* RegistrationNumber::convert_int2str(int area_number, int serial_number)
{
    // format reg: char str[11] = {'1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0'};
    reg_str[10] = '\0';

    char* str = num2str(area_number);
    int i = 1;
    int j = len_str(str)-1;
    while (i >= 0)
    {
        if( is_int_char(str[j]) && j>=0 ) { reg_str[i] = str[j]; }
        else                              { reg_str[i] = '0';    }
        i--;
        j--;
    }
    delete[] str;

    reg_str[2] = '-';

    str = num2str(serial_number);
    i = len_str(reg_str)-1;
    j = len_str(str)-1;
    while (i > 2)
    {
        if( is_int_char(str[j]) && j>=0 ) { reg_str[i] = str[j]; }
        else                              { reg_str[i] = '0';    }
        i--;
        j--;
    }
    delete[] str;


    return reg_str;
}

void  RegistrationNumber::convert_str2int(char str[11])
{
    str[2] = '0'; // repair '-' in str
    int num = str2num(str);
    int a = num / int(pow(10, 8));
    int s = num % int(pow(10, 8));

    this->set_reg(a, s);
}

RegistrationNumber::RegistrationNumber()
{
    log_warning("RegistrationNumber", "RegistrationNumber", "constructor work " << this)
    reg_str = new char[11] {'0', '0', '-', '0', '0', '0', '0', '0', '0', '0', '\0'};
    this->set_reg(0, 0);
}

RegistrationNumber::~RegistrationNumber()
{
    log_warning("RegistrationNumber", "~RegistrationNumber", "destruct work " << this);
    delete[] reg_str;
}

RegistrationNumber::RegistrationNumber(char str[11])
{
    log_warning("RegistrationNumber", "RegistrationNumber", "constructor work " << this)
    reg_str = new char[11] {'0', '0', '-', '0', '0', '0', '0', '0', '0', '0', '\0'};
    convert_str2int(str);
}

RegistrationNumber::RegistrationNumber(int a, int s)
{
    log_warning("RegistrationNumber", "RegistrationNumber", "constructor work " << this)
    reg_str = new char[11] {'0', '0', '-', '0', '0', '0', '0', '0', '0', '0', '\0'};
    this->set_reg(a, s);
}

RegistrationNumber::RegistrationNumber(const RegistrationNumber &obj)
{
    log_warning("RegistrationNumber", "RegistrationNumber", "copy construct work");
    log_warning("RegistrationNumber", "RegistrationNumber", "copy from " << &obj);
    log_warning("RegistrationNumber", "RegistrationNumber", "copy to   " << this);

    this->reg_str = new char[11]{ '0', '0', '-', '0', '0', '0', '0', '0', '0', '0', '\0' };

    this->area_number   = obj.area_number;
    this->serial_number = obj.serial_number;

}

void  RegistrationNumber::set_reg(int a, int s)
{
    if ( (0 <= a) && (a < 100) ) { area_number = a; }
    else                         { area_number = 0; }

    if ( (0 <= s) && (s < pow(10, 7)) ) { serial_number = s; }
    else                                { serial_number = 0; }
}

void  RegistrationNumber::set_reg(char str[11])
{
    convert_str2int(str);
}

char* RegistrationNumber::get_reg()
{
    return convert_int2str(area_number, serial_number);
}

bool  RegistrationNumber::check_reg()
{
    if ( 0 <= area_number && area_number < 100 && 
         0 <= serial_number && serial_number < pow(10, 7) ) { return true; }
    else { return false; }

}

std::ostream&  operator<< (std::ostream&  out,  RegistrationNumber &obj)
{
    char* str = obj.convert_int2str(obj.area_number, obj.serial_number);

    int i = 0;
    while (str[i] != '\0')
    {
        out << str[i];
        i++;
    }
   
    return out;
}

std::istream&  operator>> (std::istream&  in,   RegistrationNumber &obj)
{
    int a, s;
    cout << "area_number   : "; in >> a;
    cout << "serial_number : "; in >> s;

    obj.set_reg(a, s);

    return in;

}


