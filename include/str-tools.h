#pragma once

// for symbols - >

bool is_int      (int );
bool is_char     (char);
bool is_int_char (char);
char int2char (int );
int  char2int (char);

// for lines - >

bool is_numstr  (char*);
bool is_charstr (char*);
char* num2str (int  );
int   str2num (char*);

int  len_num(int);
int  len_str(char*);
void outstr(char*);


