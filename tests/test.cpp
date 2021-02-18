#include "pch.h"
#include ".\..\src\str-tools.cpp"
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
