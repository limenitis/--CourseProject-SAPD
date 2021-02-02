#pragma once
#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#define cout wcout
#define cerr wcerr

using namespace std;

wstring gen_rand_key();

class HashTable 
{
private:
	int N = 2500;
	wstring segment[2500][3]{L""};
public:
	void push_element(wstring key, int mode = 0) 
	{
		if (correct_key(key)) 
		{	
			int c = 0;
			int id = get_hash(key);
			wstring conflict = L"";
			if ( (segment[id][0] == L"") || (segment[id][0] == L"<delete>") ) // is empty
			{
				segment[id][0] = key;
				if (mode) { green_out(L"[push_element] : success"); }
			}
			else 
			{
				id = (id + get_hash_conflict(key)) % N;
				while ( ((segment[id][0] != L"") && (segment[id][0] != L"<delete>")) )
				{
					conflict = conflict + L" " + to_wstring(id);
					id = ( id + get_hash_conflict(key) ) % N;
				}

				if ((segment[id][0] == L"") || (segment[id][0] == L"<delete>"))
				{
					segment[id][0] = key;
					segment[id][1] = conflict;
					if (mode) { green_out(L"[push_element] : success"); }
				}
				else
				{
					red_out(L"[push_element] : failure : id busy : ignore element"); 
				}
			}
		}
		else 
		{ 
			if (mode) { red_out(L"[push_element] : key don't correct"); } 
		}
	}

	void del_element(wstring key) 
	{
		if (correct_key(key))
		{
			int id = get_hash(key);
			int pos = find_key(key);

			if (pos == -1)
			{
				red_out(L"[delete element] key don't found");
			}
			else { segment[pos][0] = L"<delete>"; green_out(L"[delete_element] : success"); }
		}
		else { red_out(L"[delete element] key don't correct"); }
	}

	int find_key(wstring key)
	{
		if (correct_key(key))
		{
			int id = get_hash(key);
			int stop_id = id;

			while ( segment[id][0] != key) 
			{
				id = (id + get_hash_conflict(key)) % N;
				if (id == stop_id) { break; }
			}

			if (segment[id][0] == key) { return id; }
			else { return -1; } // err 
		}
		else { red_out(L"[find key] key don't correct"); }
	}

	bool correct_key(wstring key)
	{
		if (key.size() != 6) { return false; }

		if (  is_char  (key[0])
		&&    is_num_c (key[1]) 
		&&    is_num_c (key[2])
		&&	  is_num_c (key[3])
		&&    is_char  (key[4])
		&&    is_char  (key[5]) ) { return true; }

		else { return false; }
	}

	int get_hash(wstring key)
	{
		if (correct_key(key))
		{
			int sum_key = 0;
			for (int i = 0; i < key.size(); i++) 
			{
				sum_key += key[i] * pow(2, i);
			}

			if (sum_key < 0) { return -1; }
			else { return(sum_key) % N; }
		}
		else
		{
			return -1;
		}
	}

	int get_hash_conflict(wstring key) 
	{
		if (correct_key(key))
		{
			int sum_key = 0;
			for (int i = 0; i < key.size(); i++)
			{
				sum_key += key[i] * pow(5, i);
			}

			if (sum_key < 0) { return -1; }
			else { return(sum_key) % N; }
		}
		else
		{
			return -1;
		}
	}

	void print(int from = 0, int to = 2500)
	{
		if (0 < from && to > N) { red_out(L"[print] : id don't correct"); return; }

		int c = 0;
		for (int i = from; i < to; i++)
		{
			if ((segment[i][0] == L"") || (segment[i][0] == L"<delete>")) // is empty
			{
				segment[i][2] = to_wstring(0);
			}
			else
			{
				c = 0;
				if (segment[i][0] == L"") { segment[i][2] = to_wstring(0); }
				else { c++; }

				for (auto i : segment[i][1]) // for conflict 
				{
					if (i == L' ') { c++;}
				}
				segment[i][2] = to_wstring(c);
			}
			cout << i + 1 << L" :: " << segment[i][2] << L" :: " << segment[i][0] << L" :: " << segment[i][1] << endl;
		}
	}

	void save() 
	{
		int c = 0;
		for (int i = 0; i < N; i++)
		{
			if ((segment[i][0] == L"") || (segment[i][0] == L"<delete>")) // is empty
			{
				segment[i][2] = to_wstring(0);
			}
			else
			{
				c = 0;
				if (segment[i][0] == L"") { segment[i][2] = to_wstring(0); }
				else { c++; }

				for (auto i : segment[i][1]) // for conflict 
				{
					if (i == L' ') { c++; }
				}
				segment[i][2] = to_wstring(c);
			}
			cerr << i + 1 << L" :: " << segment[i][2] << L" :: " << segment[i][0] << L" :: " << segment[i][1] << "\"" << endl;
		}
	}


	friend bool is_num_c(char num);
	friend bool is_num_i(int num);
};

wstring gen_rand_key()
{
	wstring key = L"";
	bool format[] = { 1, 0, 0, 0, 1, 1 };  // char -> 1		int -> 0
	int MIN_VALUE_C = 65;
	int MAX_VALUE_C = 122;
	int MIN_VALUE_I = 0;
	int MAX_VALUE_I = 9;

	int tmp;
	for (bool f : format)
	{
		if (f) // char
		{
			tmp = MIN_VALUE_C + rand() % MAX_VALUE_C;
			while (!is_char(tmp))
			{
				tmp = MIN_VALUE_C + rand() % MAX_VALUE_C;
			}
			key += tmp;
		}
		else   // int
		{
			tmp = MIN_VALUE_I + rand() % MAX_VALUE_I;
			while (!is_num_i(tmp))
			{
				tmp = MIN_VALUE_I + rand() % MAX_VALUE_I;
			}
			key += num2char(tmp);
		}
	}
	return key;
}

bool is_num_c(char num)
{
	char nums[] = { '1','2','3','4','5','6','7','8','9','0' };
	for (auto i : nums)
	{
		if (num == i) { return true; }
	}
	return false;
}

bool is_num_i(int num)
{
	int nums[] = { 1,2,3,4,5,6,7,8,9,0 };
	for (auto i : nums)
	{
		if (num == i) { return true; }
	}
	return false;
}

bool is_char(int c)
{
	if ((64 < c) && (c < 91) || (96 < c) && (c < 123)) { return true; }
	else { return false; }
}

char num2char(int i) // 48 char == 0 int
{
	return i + 48;
}

int char2int(char c) // 48 char == 0 int
{
	return c - 48;
}

void green_out(wstring str)
{
	wstring green_start = L"\x1b[32m";
	wstring green_end = L"\x1b[0m";

	wcout << green_start << str << green_end << endl;
}

void red_out(wstring str)
{
	wstring red_start = L"\x1b[31m";
	wstring red_end = L"\x1b[0m";

	wcout << red_start << str << red_end << endl;
}
