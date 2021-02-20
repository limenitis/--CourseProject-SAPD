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

    std::string str = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    for(auto i : str) 
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

  TEST(Checks, len_str) {
  	EXPECT_EQ(6, len_str("000000"));
  	EXPECT_EQ(6, len_str("asfrfa"));
  	EXPECT_EQ(6, len_str("3$%7^&"));
  	EXPECT_EQ(6, len_str("3$2%Fd"));
  	EXPECT_EQ(6, len_str("%2aQ3%"));
  	EXPECT_EQ(6, len_str("%S3$1f"));
  	EXPECT_EQ(6, len_str("ref34a"));
  	EXPECT_NE(6, len_str("вфаУ42"));
    EXPECT_NE(6, len_str("%вЦ;1:"));
    EXPECT_NE(6, len_str("Ац4В,."));
  }

  TEST(Checks, len_num) {
  	EXPECT_EQ(9, len_num(111111111));
  	EXPECT_EQ(9, len_num(123456789));
  	EXPECT_EQ(9, len_num(987654321));
  	EXPECT_EQ(9, len_num(345736831));
  	EXPECT_EQ(9, len_num(947275826));
  	EXPECT_EQ(6, len_num(   111111));
    EXPECT_EQ(6, len_num(   348374));
    EXPECT_EQ(6, len_num(   237855));
  	EXPECT_EQ(1, len_num(        1));
  	EXPECT_EQ(1, len_num(        0));
  }

  TEST(Checks, is_numstr) {
  	EXPECT_TRUE  (is_numstr("0484937985"));
  	EXPECT_TRUE  (is_numstr("0123456789"));
  	EXPECT_TRUE  (is_numstr("1234567890"));
  	EXPECT_TRUE  (is_numstr("4020572057"));
  	EXPECT_TRUE  (is_numstr("8402750740"));
  	EXPECT_FALSE (is_numstr("3957d94759"));
    EXPECT_FALSE (is_numstr("d948028570"));
    EXPECT_FALSE (is_numstr("klsdli4038"));
  	EXPECT_FALSE (is_numstr("387502705f"));
  	EXPECT_FALSE (is_numstr("nducnriwxo"));
  }

  TEST(Checks, is_charstr) {
  	EXPECT_FALSE (is_charstr("0484937985")); 
  	EXPECT_FALSE (is_charstr("0123456789")); 
  	EXPECT_FALSE (is_charstr("1234567890")); 
  	EXPECT_FALSE (is_charstr("4020572057")); 
  	EXPECT_FALSE (is_charstr("8402750740")); 
  	EXPECT_FALSE (is_charstr("3957d94759")); 
    EXPECT_FALSE (is_charstr("d948028570")); 
    EXPECT_FALSE (is_charstr("klsdli4038")); 
  	EXPECT_FALSE (is_charstr("387502705f")); 
    EXPECT_FALSE (is_charstr("ALR.dimros"));
    EXPECT_TRUE  (is_charstr("nducnriwxo"));
    EXPECT_TRUE  (is_charstr("dkrmriMEIC")); 
    EXPECT_TRUE  (is_charstr("DJOSndjrno")); 
  }

  TEST(Checks, str2num) {
  	EXPECT_EQ( 484937985, str2num("0484937985")); 
  	EXPECT_EQ( 123456789, str2num("0123456789")); 
  	EXPECT_EQ(1234567890, str2num("1234567890")); 
  	EXPECT_EQ(4020572057, str2num("4020572057")); 
  	EXPECT_EQ(8402750740, str2num("8402750740")); 
  	EXPECT_EQ(1111111111, str2num("1111111111")); 
  	EXPECT_EQ(9857654321, str2num("9857654321")); 
  	EXPECT_EQ(3457836831, str2num("3457836831")); 
  	EXPECT_EQ(9472725826, str2num("9472725826")); 
  	EXPECT_EQ(     25826, str2num("0000025826")); 

    EXPECT_NE(   1111111, str2num("   1111111")); // return -579019705 ( because spaces )
    EXPECT_NE(   3486374, str2num("   3486374")); // return -576644442 ( because spaces )
    EXPECT_NE(   2378355, str2num("   2378355")); // return -577752461 ( because spaces )
  	EXPECT_NE(         1, str2num("         1")); // return -597908575 ( because spaces )
  	EXPECT_NE(         0, str2num("         0")); // return -597908576 ( because spaces )
  }

  TEST(Checks, num2str) {
  	EXPECT_STREQ( "484937985", num2str( 484937985)); 
  	EXPECT_STREQ( "123456789", num2str( 123456789)); 
  	EXPECT_STREQ("1234567890", num2str(1234567890)); 
    EXPECT_STREQ("4020572057", num2str(4020572057));
  	EXPECT_STREQ("8402750740", num2str(8402750740)); 
  	EXPECT_STREQ("1111111111", num2str(1111111111)); 
  	EXPECT_STREQ("9857654321", num2str(9857654321)); 
  	EXPECT_STREQ("3457836831", num2str(3457836831)); 
  	EXPECT_STREQ("9472725826", num2str(9472725826)); 
  	EXPECT_STREQ(     "25826", num2str(     25826)); 
  	EXPECT_STREQ(   "1111111", num2str(   1111111)); 
    EXPECT_STREQ(   "3486374", num2str(   3486374)); 
    EXPECT_STREQ(   "2378355", num2str(   2378355)); 
  	EXPECT_STREQ(         "1", num2str(         1)); 
  	EXPECT_STREQ(         "0", num2str(         0)); 
  }
}

namespace test_Structures
{
    TEST(TestDate, Constructor_Default) {
        Date obj;
        EXPECT_STREQ("00.00.0000", obj.get_date());
    }

    TEST(TestDate, Constructor_int) {
        Date obj1(12, 1, 2021);
        EXPECT_STREQ("12.01.2021", obj1.get_date());

        Date obj2(30, 2, 2021);
        EXPECT_STREQ("00.02.2021", obj2.get_date());

        Date obj3(32, 1, 2021);
        EXPECT_STREQ("00.01.2021", obj3.get_date());

        Date obj4(12, 15, 2021);
        EXPECT_STREQ("00.00.2021", obj4.get_date());

        Date obj5(12, 1, -2021);
        EXPECT_STREQ("12.01.0000", obj5.get_date());

        Date obj6(32, 15, -2021);
        EXPECT_STREQ("00.00.0000", obj6.get_date());
    }

    TEST(TestDate, Constructor_str) {
        std::string str;

        str = "12.01.2021";
        Date obj1(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12.01.2021", obj1.get_date());
        
        str = "30.02.2021";
        Date obj2(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.02.2021", obj2.get_date());

        str = "32.01.2021";
        Date obj3(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.01.2021", obj3.get_date());

        str = "12.15.2021";
        Date obj4(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.00.2021", obj4.get_date());

        str = "12.01.-200";
        Date obj5(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12.01.0000", obj5.get_date());

        str = "32.15.-200";
        Date obj6(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.00.0000", obj6.get_date());        
    }

    TEST(TestDate, SetDate_int) {
        Date obj;

        obj.set_date(12, 1, 2021);
        EXPECT_STREQ("12.01.2021", obj.get_date());

        obj.set_date(30, 2, 2021);
        EXPECT_STREQ("00.02.2021", obj.get_date());

        obj.set_date(32, 1, 2021);
        EXPECT_STREQ("00.01.2021", obj.get_date());

        obj.set_date(12, 15, 2021);
        EXPECT_STREQ("00.00.2021", obj.get_date());

        obj.set_date(12, 1, -2021);
        EXPECT_STREQ("12.01.0000", obj.get_date());

        obj.set_date(32, 15, -2021);
        EXPECT_STREQ("00.00.0000", obj.get_date());

        obj.set_date(30, 2, 2002);
        EXPECT_STREQ("00.02.2002", obj.get_date());

        obj.set_date(80, 80, -100);
        EXPECT_STREQ("00.00.0000", obj.get_date());

        obj.set_date(-1, -1, -10);
        EXPECT_STREQ("00.00.0000", obj.get_date());
    }

    TEST(TestDate, SetDate_str) {
        std::string str;
        Date obj;

        str = "12.01.2021";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12.01.2021", obj.get_date());
        
        str = "30.02.2021";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.02.2021", obj.get_date());

        str = "32.01.2021";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.01.2021", obj.get_date());

        str = "12.15.2021";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.00.2021", obj.get_date());

        str = "12.01.-200";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12.01.0000", obj.get_date());

        str = "32.15.-200";
        obj.set_date(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00.00.0000", obj.get_date());        
    }

    TEST(TestTime, Constructor_Default) {
        Time obj;
        EXPECT_STREQ("00:00", obj.get_time());
    }

    TEST(TestTime, Constructor_int) {
        Time obj1(12, 25);
        EXPECT_STREQ("12:25", obj1.get_time());

        Time obj2(24, 60);
        EXPECT_STREQ("00:00", obj2.get_time());

        Time obj3(-1, -1);
        EXPECT_STREQ("00:00", obj3.get_time());

        Time obj4(23, 59);
        EXPECT_STREQ("23:59", obj4.get_time());

        Time obj5(24, 59);
        EXPECT_STREQ("00:59", obj5.get_time());

        Time obj6(25, 59);
        EXPECT_STREQ("00:59", obj6.get_time());

        Time obj7(22, 60);
        EXPECT_STREQ("22:00", obj7.get_time());
    }

    TEST(TestTime, Constructor_str) {
        std::string str;

        str = "12:25";
        Time obj1(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12:25", obj1.get_time());

        str = "24:60";
        Time obj2(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:00", obj2.get_time());

        str = "-1:-1";
        Time obj3(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:00", obj3.get_time());

        str = "23:59";
        Time obj4(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("23:59", obj4.get_time());

        str = "24:59";
        Time obj5(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:59", obj5.get_time());

        str = "25:59";
        Time obj6(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:59", obj6.get_time());

        str = "22:60";
        Time obj7(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("22:00", obj7.get_time());
    }

    TEST(TestTime, SetDate_int) {
        Time obj;

        obj.set_time(12, 25);
        EXPECT_STREQ("12:25", obj.get_time());

        obj.set_time(24, 60);
        EXPECT_STREQ("00:00", obj.get_time());

        obj.set_time(-1, -1);
        EXPECT_STREQ("00:00", obj.get_time());

        obj.set_time(23, 59);
        EXPECT_STREQ("23:59", obj.get_time());

        obj.set_time(24, 59);
        EXPECT_STREQ("00:59", obj.get_time());

        obj.set_time(25, 59);
        EXPECT_STREQ("00:59", obj.get_time());

        obj.set_time(22, 60);
        EXPECT_STREQ("22:00", obj.get_time());
    }

    TEST(TestTime, SetDate_str) {
        std::string str;
        Time obj;

        str = "12:25";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12:25", obj.get_time());

        str = "24:60";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:00", obj.get_time());

        str = "-1:-1";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:00", obj.get_time());

        str = "23:59";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("23:59", obj.get_time());

        str = "24:59";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:59", obj.get_time());

        str = "25:59";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00:59", obj.get_time());

        str = "22:60";
        obj.set_time(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("22:00", obj.get_time());
    }

    TEST(TestTime, operators) {
        Time t1, t2;

        t1.set_time(12, 00);
        t2.set_time(15, 00);
        EXPECT_TRUE(t1 < t2);

        t1.set_time(10, 00);
        t2.set_time(19, 00);
        EXPECT_TRUE(t1 < t2);

        t1.set_time(15, 00);
        t2.set_time(12, 00);
        EXPECT_TRUE(t1 > t2);
    }

    TEST(TestRegistrationNumber, Constructor_Default) {
        RegistrationNumber obj;
        EXPECT_STREQ("00-0000000", obj.get_reg());
    }

    TEST(TestRegistrationNumber, Constructor_int) {
        RegistrationNumber obj1(12, 3456789);
        EXPECT_STREQ("12-3456789", obj1.get_reg());

        RegistrationNumber obj2(00, 0);
        EXPECT_STREQ("00-0000000", obj2.get_reg());

        RegistrationNumber obj3(100, 34567891);
        EXPECT_STREQ("00-0000000", obj3.get_reg());

        RegistrationNumber obj4(-1, -1);
        EXPECT_STREQ("00-0000000", obj4.get_reg());

        RegistrationNumber obj5(2, 1020);
        EXPECT_STREQ("02-0001020", obj5.get_reg());

        RegistrationNumber obj6(12, 353);
        EXPECT_STREQ("12-0000353", obj6.get_reg());
    }

    TEST(TestRegistrationNumber, Constructor_str) {
        std::string str;

        str = "12-3456789";
        RegistrationNumber obj1(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12-3456789", obj1.get_reg());

        str = "00-0000000";
        RegistrationNumber obj2(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj2.get_reg());

        str = "00-0000000";
        RegistrationNumber obj3(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj3.get_reg());

        str = "00-0000000";
        RegistrationNumber obj4(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj4.get_reg());

        str = "02-0001020";
        RegistrationNumber obj5(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("02-0001020", obj5.get_reg());

        str = "12-0000353";
        RegistrationNumber obj6(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12-0000353", obj6.get_reg());
    }

    TEST(TestRegistrationNumber, SetDate_int) {
        RegistrationNumber obj;

        obj.set_reg(12, 3456789);
        EXPECT_STREQ("12-3456789", obj.get_reg());

        obj.set_reg(00, 0);
        EXPECT_STREQ("00-0000000", obj.get_reg());

        obj.set_reg(100, 34567891);
        EXPECT_STREQ("00-0000000", obj.get_reg());

        obj.set_reg(-1, -1);
        EXPECT_STREQ("00-0000000", obj.get_reg());

        obj.set_reg(2, 1020);
        EXPECT_STREQ("02-0001020", obj.get_reg());

        obj.set_reg(12, 353);
        EXPECT_STREQ("12-0000353", obj.get_reg());
    }

    TEST(TestRegistrationNumber, SetDate_str) {
        std::string str;
        RegistrationNumber obj;

        str = "12-3456789";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12-3456789", obj.get_reg());

        str = "00-0000000";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj.get_reg());

        str = "00-0000000";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj.get_reg());

        str = "00-0000000";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("00-0000000", obj.get_reg());

        str = "02-0001020";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("02-0001020", obj.get_reg());

        str = "12-0000353";
        obj.set_reg(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("12-0000353", obj.get_reg());
    }

    TEST(TestSchedule, Constructor_Default) {
        Schedule obj;
        EXPECT_STREQ("00:00-00:00", obj.get_schedule());
    }

    TEST(TestSchedule, Constructor_Time) {
        Time t1(10 ,00);
        Time t2(19, 00);
        Schedule obj(t1, t2);
        EXPECT_STREQ("10:00-19:00", obj.get_schedule());
    }

    TEST(TestSchedule, Constructor_str) {
        std::string str = "10:00-18:00";

        Schedule obj(const_cast<char*>(str.c_str()));
        EXPECT_STREQ("10:00-18:00", obj.get_schedule());
    }

    TEST(TestSchedule, SetDate_Time) {
        Time t1(10, 00);
        Time t2(16, 00);
        Schedule obj(t1, t2);
        EXPECT_STREQ("10:00-16:00", obj.get_schedule());
    }

    TEST(TestSchedule, SetDate_str) {
        Schedule obj;
        obj.set_schedule("12:00-15:00");
        EXPECT_STREQ("12:00-15:00", obj.get_schedule());
    }
}
