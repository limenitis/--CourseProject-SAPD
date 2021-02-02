#include ".\..\include\RegistrationNumber.h"

class Patient
{
protected:
    RegistrationNumber reg_num;
    char patient_name[100] = {'\0'};
    char work_place[100] = {'\0'};
    char addres[120] = {'\0'};
    int  year_born;

public:
    Patient();
    Patient(/* params */);
    bool check_patient_data();
};
