#include "pch.h"

#include ".\..\src\str-tools.cpp"
#include ".\..\src\Time.cpp"
#include ".\..\src\Date.cpp"
#include ".\..\src\Schedule.cpp"
#include ".\..\src\Time.cpp"
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
}

