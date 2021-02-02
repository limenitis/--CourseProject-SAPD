#pragma once
#include ".\..\include\Schedule.h"
#include <iostream>
using namespace std;


class Doctor
{
protected:
    Schedule schedule;
    int cabinet_number;
    char doctor_name[25] = {'\0'};
    char specialization[50] = {'\0'}; 
    // Самая длинная специализация врача - 35(39)
    // Специалист по клеточным технологиям

public:
    Doctor();
    Doctor(/* params */);

    bool check_doctor_data();
};
