#pragma once

// for symbols - >

bool is_int      (int32_t);
bool is_char     (char   );
bool is_int_char (char   );

char     int2char (int16_t);
int16_t  char2int (char   );

// for lines - >

bool is_numstr  (char*);
bool is_charstr (char*);

char*   num2str (int64_t);
int64_t str2num (char*  );

int64_t len_num(int64_t);
int64_t len_str(char*);
void    outstr(char*);

bool compare_str_left_over(char*, char*);
bool compare_str_right_over(char*, char*);
bool compare_str_equal(char*, char*);

