#pragma once
#include <iostream>
using namespace std;



class HashTable 
{
private:
	int N = 2500;
	char* segment[2500]{'\0'};

	bool correct_key (char* key);
	int get_hash          (char* key);
	int get_hash_conflict (char* key);
public:

	bool insert	  (char* key);
	bool remove   (char* key);
	int  find_key (char* key);
	void print    (int from = 0, int to = 2500);
};

