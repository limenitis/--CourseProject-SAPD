#pragma once
#include <iostream>
// #include <fstream>
#include "str-tools.h"

using namespace std;

class Time
{
private:
    // format time: char str[6] = {'0','0',':','0','0','\0'};
    int hour;
    int minute;

    void convert_int2str(int hour, int minute);
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


class Date
{
private:
    // format date: char str[11] = {'0', '0', '.', '0', '0', '.', '0', '0', '0', '0', '\0'};
    int day;
    int month;
    int year;

    void convert_int2str(int day, int month, int year);
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


class RegistrationNumber
{
private:
    // format reg: char str[11] = {'1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0'};
    int area_number;
    int serial_number;

    void convert_int2str(int area_number, int serial_number);
    void convert_str2int(char str[11]);

public:
    RegistrationNumber();
    RegistrationNumber(char str[11]);
    RegistrationNumber(int area_number, int serial_number);

    void  set_reg(int area_number, int serial_number);
    void  set_reg(char str[11]);
    char* get_reg();
    bool  check_reg();

    friend std::ostream&  operator<< (std::ostream&  out,  RegistrationNumber &obj);
    friend std::istream&  operator>> (std::istream&  in,   RegistrationNumber &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, RegistrationNumber &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  RegistrationNumber &obj);
};


class Schedule
{
private:
    // format Schedule: char str[12] = {'1', '0', ':', '0', '0', '-', '1', '8', ':', '0', '0', '\0'};
    Time start_time;
    Time finish_time;

    void convert_int2str(Time start_time, Time finish_time);
    void convert_str2int(char str[12]);

public:
    Schedule();
    Schedule(char str[12]);
    Schedule(Time start_time, Time finish_time);

    void  set_schedule(Time start_time, Time finish_time);
    void  set_schedule(char str[12]);
    char* get_schedule();
    bool  check_sched();

    friend std::ostream&  operator<< (std::ostream&  out,  Schedule &obj);
    friend std::istream&  operator>> (std::istream&  in,   Schedule &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Schedule &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Schedule &obj);
};


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


class Direction : private Patient, private Doctor 
{
private:
    Doctor  *doctor_ptr;
    Patient *patient_ptr;
    Date direction_date;
    Time direction_time;

public:
    Direction(Doctor *doctor, Patient *patient, Date date, Time time);

    void get_data(RegistrationNumber num, char doctor_name[25], Date date, Time time);

    friend std::ostream&  operator<< (std::ostream&  out,  Direction &obj);
    friend std::istream&  operator>> (std::istream&  in,   Direction &obj);
    // friend std::ofstream& operator<< (std::ofstream& fout, Direction &obj);
    // friend std::ifstream& operator>> (std::ifstream& fin,  Direction &obj);
};


class Hospital{
};



// https://med-tutorial.ru/med-doctors/
//
// Акушер
// Акушер-гинеколог
// Аллерголог
// Андролог
// Анестезиолог
// Венеролог
// Вертебролог
// Врач ЛФК
// Врач функциональной диагностики
// Врач-цитолог
// Гастроэнтеролог
// Гематолог
// Генетик
// Гепатолог
// Гинеколог
// Гинеколог-эндокринолог
// Гирудотерапевт
// Гомеопат
// Дерматолог
// Диетолог
// Иммунолог
// Инфекционист
// Кардиолог
// Кардиохирург
// Кинезиолог
// Колопроктолог
// Косметолог
// Логопед
// Маммолог
// Мануальный терапевт
// Массажист
// Миколог
// Нарколог
// Невролог
// Нейрохирург
// Неонатолог
// Нефролог
// Окулист (офтальмолог)
// Онкогинеколог
// Онкодерматолог
// Онколог
// Ортопед
// Остеопат
// Отоларинголог
// Педиатр
// Пластический хирург
// Подолог
// Проктолог
// Психиатр
// Психолог
// Психотерапевт
// Пульмонолог
// Реабилитолог
// Ревматолог
// Рентгенолог
// Репродуктолог
// Рефлексотерапевт
// Сексолог
// Семейный врач
// Сомнолог
// Сосудистый хирург
// Специалист по клеточным технологиям
// Спортивный врач
// Стоматолог
// Стоматолог-гигиенист
// Стоматолог-имплантолог
// Стоматолог-ортодонт
// Стоматолог-ортопед
// Стоматолог-пародонтолог
// Стоматолог-терапевт
// Стоматолог-хирург
// Сурдолог
// Терапевт
// Травматолог
// Трихолог
// УЗИ-специалист
// Уролог
// Физиотерапевт
// Флеболог
// Фтизиатр
// Хирург
// Челюстно-лицевой хирург
// Эндокринолог
// Эндоскопист
// Эпилептологи

// http://wordsteps.com/vocabulary/words/136790/%D0%9D%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5+%D0%B2%D1%80%D0%B0%D1%87%D0%B5%D0%B9+%D0%BD%D0%B0+%D0%B0%D0%BD%D0%B3%D0%BB%D0%B8%D0%B9%D1%81%D0%BA%D0%BE%D0%BC
// 
// dentist
// дантист
// surgeon
// хирург
// urologist
// уролог
// neurologist
// невропатолог
// psychiatrist
// психиатр
// otolaryngologist
// отоларинголог
// obstetrician
// акушер
// dermatologist
// дерматолог
// cardiologist
// кардиолог
// endocrinologist
// эндокринолог
// oncologist
// онколог
// rheumatologist
// ревматолог
// nephrologist
// нефролог
// pediatrician
// педиатр
// podiatrist
// врач-ортопед
// ophthalmologist
// окулист, офтальмолог
// radiologist
// рентгенолог
// gynecologist
// гинеколог
// geneticist
// генетик
// physiologist
// физиолог
// allergist
// аллерголог
// neurosurgeon
// нейрохирург
// hematologist
// гематолог
// microbiologist
// микробиолог
// epidemiologist
// эпидемиолог
// anaesthesiologist
// анестезиолог
// family medicine physician
// семейный врач-терапевт
// gastroenterologist
// гастроэнтеролог
// immunologist
// иммунолог
// infectious disease specialist
// специалист по инфекционным заболеваниям
// intensivist
// реаниматолог
// neonatologist
// неонатолог
// orthopedic surgeon
// хирург-ортопед
// palliative care specialist
// специалист по паллиативной медицине
// parasitologist
// паразитолог
// plastic surgeon
// пластический хирург
// pulmonologist
// пульмонолог
// sleep disorders specialist
// специалист, который лечит расстройства сна
// sports medicine specialist
// спортивный врач


// адрес взятый случайным способом из области крупного города (80):
// чтобы в длину строки входили: область, район, город/поселок, страна, дом, корпус
//
// деревня Новое Девяткино, 43/1, Всеволожский район, Ленинградская область, Россия

// место работы указано как и длинна ФИО потому что ИП = ФИО, а 
// название организации больше 100 символов придумать сложно и 
// не эффективно с точки зрения подачи компании для потребителя


