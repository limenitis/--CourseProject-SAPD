#include "pch.h"

#include ".\..\src\str-tools.cpp"
#include ".\..\src\Time.cpp"
#include ".\..\src\Date.cpp"
#include ".\..\src\Schedule.cpp"
#include ".\..\src\RegistrationNumber.cpp"

#include <string>

std::string str1 = "";
std::string str2 = "";

namespace test_str_tools
{
  TEST(Compare_Str, LeftStrOver_LeftLonger) {
    str1 = "Масленников";
    str2 = "Белов";
    EXPECT_TRUE(compare_str_left_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, LeftStrOver_RightLonger) {
  	str1 = "Юрченко";
  	str2 = "Гордиенко";
  	EXPECT_TRUE(compare_str_left_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, LeftStrOver_EqualLength) {
  	str1 = "Быстрова";
  	str2 = "Аргокова";
  	EXPECT_TRUE(compare_str_left_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, LeftStrOver_FewWords_ReturnOnFirst) {
  	str1 = "Юрченко Вадим"; 
  	str2 = "Аргокова Дарья";
  	EXPECT_TRUE(compare_str_left_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, LeftStrOver_FewWords_ReturnAfterFirst) {
  	str1 = "Рррр Дарья";
  	str2 = "Рррр Вадим";
  	EXPECT_TRUE(compare_str_left_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, RightStrOver_RightLonger) {
    str1 = "Белов";
    str2 = "Масленников";
    EXPECT_TRUE(compare_str_right_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, RightStrOver_LeftLonger) {
  	str1 = "Гордиенко";
  	str2 = "Юрченко";
  	EXPECT_TRUE(compare_str_right_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, RightStrOver_EqualLength) {
  	str1 = "Аргокова";
  	str2 = "Быстрова";
  	EXPECT_TRUE(compare_str_right_over(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, EqualStr_FewWord) {
  	str1 = "Аргокова Дарья"; 
  	str2 = "Юрченко Вадим ";
  	EXPECT_FALSE(compare_str_equal(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, EqualStr_FewWord_EqualLength_WithSpaces) {
  	str1 = "Мм ммм";
  	str2 = "Мм ммм";
  	EXPECT_TRUE(compare_str_equal(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Compare_Str, EqualStr_FewWord_EqualLength) {
  	str1 = "Ммммм"; 
  	str2 = "Ммммм";
  	EXPECT_TRUE(compare_str_equal(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str())));
  }

  TEST(Convertation_functions, int2char) {
  	EXPECT_EQ('0', int2char(0));
  	EXPECT_EQ('1', int2char(1));
  	EXPECT_EQ('2', int2char(2));
  	EXPECT_EQ('3', int2char(3));
  	EXPECT_EQ('4', int2char(4));
  	EXPECT_EQ('5', int2char(5));
  	EXPECT_EQ('6', int2char(6));
  	EXPECT_EQ('7', int2char(7));
  	EXPECT_EQ('8', int2char(8));
  	EXPECT_EQ('9', int2char(9));
  }

  TEST(Convertation_functions, char2int) {
  	EXPECT_EQ(0, char2int('0'));
  	EXPECT_EQ(1, char2int('1'));
  	EXPECT_EQ(2, char2int('2'));
  	EXPECT_EQ(3, char2int('3'));
  	EXPECT_EQ(4, char2int('4'));
  	EXPECT_EQ(5, char2int('5'));
  	EXPECT_EQ(6, char2int('6'));
  	EXPECT_EQ(7, char2int('7'));
  	EXPECT_EQ(8, char2int('8'));
  	EXPECT_EQ(9, char2int('9'));
  }

  TEST(Checks, is_int) {

    for (int i = 10; i < 1000000; i++)
    {
      EXPECT_FALSE(is_int(i));
    }

    for (int i = -1000000; i < 0; i++)
    {
      EXPECT_FALSE(is_int(i));
    }

    EXPECT_TRUE(is_int(0));
    EXPECT_TRUE(is_int(1));
    EXPECT_TRUE(is_int(2));
    EXPECT_TRUE(is_int(3));
    EXPECT_TRUE(is_int(4));
    EXPECT_TRUE(is_int(5));
    EXPECT_TRUE(is_int(6));
    EXPECT_TRUE(is_int(7));
    EXPECT_TRUE(is_int(8));
    EXPECT_TRUE(is_int(9));
  }

  TEST(Checks, is_char) {
    for (char i = 'а'; i > 'я'; i++)
    {
      EXPECT_TRUE(is_char(i));
    } 

    for (int i = 'a'; i < 'z'; i++)
    {
      EXPECT_TRUE(is_char(i));
    }

    EXPECT_FALSE(is_char('0'));
    EXPECT_FALSE(is_char('1'));
    EXPECT_FALSE(is_char('2'));
    EXPECT_FALSE(is_char('3'));
    EXPECT_FALSE(is_char('4'));
    EXPECT_FALSE(is_char('5'));
    EXPECT_FALSE(is_char('6'));
    EXPECT_FALSE(is_char('7'));
    EXPECT_FALSE(is_char('8'));
    EXPECT_FALSE(is_char('9'));
  }

  TEST(Checks, is_int_char) {
  	EXPECT_TRUE(is_int_char('0'));
  	EXPECT_TRUE(is_int_char('1'));
  	EXPECT_TRUE(is_int_char('2'));
  	EXPECT_TRUE(is_int_char('3'));
  	EXPECT_TRUE(is_int_char('4'));
  	EXPECT_TRUE(is_int_char('5'));
  	EXPECT_TRUE(is_int_char('6'));
  	EXPECT_TRUE(is_int_char('7'));
  	EXPECT_TRUE(is_int_char('8'));
  	EXPECT_TRUE(is_int_char('9'));
  }

  //bool is_int_char(char);
  //bool is_char(char);
  //int  len_num(int);
  //int  len_str(char*);


  //bool  is_numstr(char*);
  //bool  is_charstr(char*);
  //int   str2num(char*);
  //char* num2str(int);

}

namespace test_Structures
{
    TEST(TestDate, Constructor_Default) {
        Date obj;
        EXPECT_STREQ("00.00.0000", obj.get_date());
    }

    TEST(TestDate, Constructor_int) {
        Date obj(12, 1, 2021);
        EXPECT_STREQ("12.01.2021", obj.get_date());
    }

    TEST(TestDate, Constructor_str) {
        char str[11]{ '1','5','.','0','1', '.', '2', '0', '2', '0', '\0' };
        Date obj(str);
        EXPECT_STREQ("15.01.2020", obj.get_date());
    }

    TEST(TestDate, SetDate_str_WithPositive) {
        Date obj;
        obj.set_date(80, 80, -100);
        EXPECT_STREQ("00.00.0000", obj.get_date());
    }

    TEST(TestDate, SetDate_str_WithNegative) {
        Date obj;
        obj.set_date(-1, -1, -10);
        EXPECT_STREQ("00.00.0000", obj.get_date());
    }

    TEST(TestDate, SetDate_int) {
        Date obj;
        obj.set_date(30, 2, 2002);
        EXPECT_STREQ("00.02.2002", obj.get_date());
    }

    // ==============================================

    TEST(TestTime, Constructor_Default) {
        Time obj;
        EXPECT_STREQ("00:00", obj.get_time());
    }

    TEST(TestTime, Constructor_int) {
        Time obj(12, 00);
        EXPECT_STREQ("12:00", obj.get_time());
    }

    TEST(TestTime, Constructor_str) {
        char str[6]{ '1','5',':','0','0','\0' };
        Time obj(str);
        EXPECT_STREQ("15:00", obj.get_time());
    }

    TEST(TestTime, SetDate_str_WithPositive) {
        Time obj;
        obj.set_time(20, 50);
        EXPECT_STREQ("20.50", obj.get_time());
        obj.set_time(12, 24);
        EXPECT_STREQ("12.24", obj.get_time());
    }

    TEST(TestTime, SetDate_int) {
        Time obj;
        obj.set_time(00, 02);
        EXPECT_STREQ("00:02", obj.get_time());
    }

    // ==============================================

    TEST(RegistrationNumber, Constructor_Default) {
        RegistrationNumber obj;
        EXPECT_STREQ("00-0000000", obj.get_reg());
    }

    TEST(RegistrationNumber, Constructor_int) {
        RegistrationNumber obj(12, 353);
        EXPECT_STREQ("12-0000353", obj.get_reg());
    }

    TEST(RegistrationNumber, Constructor_str) {
        char str[11]{ '1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0' };
        RegistrationNumber obj(str);
        EXPECT_STREQ("12-3456789", obj.get_reg()); // "00-0000000"
    }

    TEST(RegistrationNumber, SetDate_str) {
        RegistrationNumber obj;
        obj.set_reg(20, 50);
        EXPECT_STREQ("20-0000050", obj.get_reg());
    }

    TEST(RegistrationNumber, SetDate_int) {
        RegistrationNumber obj;
        obj.set_reg(00, 2552302);
        EXPECT_STREQ("00-2552302", obj.get_reg());
    }

    // ==============================================

    TEST(Schedule, Constructor_Default) {
        //Schedule obj;
        //EXPECT_STREQ("12-3456789", obj.get_schedule());
    }

    TEST(Schedule, Constructor_int) {
        //Schedule obj();
        //EXPECT_STREQ("12-0000353", obj.get_schedule());
    }

    TEST(Schedule, Constructor_str) {
        //char str[11]{ '1', '2', '-', '3', '4', '5', '6', '7', '8', '9', '\0' };
        //Schedule obj(str);
        //EXPECT_STREQ("12-3456789", obj.get_schedule());
    }

    TEST(RegistratScheduleionNumber, SetDate_str) {
        //Schedule obj;
        //obj.set_schedule("12:00-15:00");
        //EXPECT_STREQ("12:00-15:00", obj.get_schedule());
    }

    TEST(Schedule, SetDate_int) {
        //Schedule obj;
        //obj.set_schedule(00, 2552302);
        //EXPECT_STREQ("00-2552302", obj.get_schedule());
    }

}
