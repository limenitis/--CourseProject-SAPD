#pragma once
#include <iostream>
#include ".\..\include\Patient.h"
#include ".\..\include\RegistrationNumber.h"

using namespace std;

class HashTableNode
{
private:
	RegistrationNumber key;
	Patient            *data;
	bool delete_data;

public:
	HashTableNode();
	bool intsert (Patient* data);
	bool remove  ();
	bool empty   ( void );
	bool deleted ( void );
	auto get_key ( void );
};


class HashTable 
{
private:
	int N = 2500;
	HashTableNode* segment[2500];

	bool correct_key       (HashTableNode *data);
	int  get_hash          (HashTableNode *data);
	int  get_hash_conflict (HashTableNode *data);

public:
	bool insert	  (HashTableNode *data);
	bool remove   (HashTableNode *data);
	int  find_key (HashTableNode *data);
	void print    (int from = 0, int to = 2500);
};

