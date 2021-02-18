#include <iostream>

bool is_int_char(char num)
{
    char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    for (auto i : nums)
    {
        if (num == i)
        {
            return true;
        }
    }
    return false;
}

bool is_int(int num)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (auto i : nums)
    {
        if (num == i)
        {
            return true;
        }
    }
    return false;
}

bool is_char(char c)
{
    if (('a' <= c) && (c <= 'z') || ('A' <= c) && (c <= 'Z'))
    {
        return true;
    }
    else if (('а' <= c) && (c <= 'я') || ('А' <= c) && (c <= 'Я'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char int2char(int i) // 48 char == 0 int (ASCII)
{
    return i + 48;
}

int char2int(char c) // 48 char == 0 int (ASCII)
{
    return c - 48;
}

int len_num(int num)
{
    int i = 1;
    while (num / int(pow(10, i)) != 0) { i++; }
    return i;
}

int len_str(char* str)
{
    int i = 0;
    while (str[i] != '\0') { i++; }
    return i;
}

char* num2str(int num)
{
    int len = len_num(num);
    char* str = new char[len+1]{'\0'};

    for (int i = len-1; i >= 0; i--)
    {
        str[len-i-1] = int2char(num / int(pow(10, i)) % 10);
    }

    return str;
}

int str2num(char* str)
{
    int num = 0;
    int len = len_str(str);

    int i = 0;
    while (str[i] != '\0')
    {
        num += char2int((int)(str[i] * pow(10, len-i-1)));
        i++;
    }

    return num;
}

bool is_numstr(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (is_int_char(str[i]) == false)
        {
            return false;
        }
        i++;
    }
    return true;
}

bool is_charstr(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (is_char(str[i]) == false)
        {
            return false;
        }
        i++;
    }
    return true;
}

void outstr(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        std::cout << str[i];
        i++;
    }
    std::cout << '\n';
}

bool compare_str_left_over(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
        {
            return true;
        }
        i++;
    }

    return false;
}

bool compare_str_right_over(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i])
        {
            return true;
        }
        i++;
    }

    return false;
}

bool compare_str_equal(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }

    return str1[i] == '\0' && str2[i] == '\0';
}

