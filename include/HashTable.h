#pragma once
#include <iostream>
#include ".\..\include\Patient.h"
#include ".\..\include\RegistrationNumber.h"

using namespace std;

class HashTableNode
{
private:
	//Patient *data = new Patient;
	Patient data;
	bool empty_data;
	bool delete_data;

public:
	HashTableNode();
	bool intsert (Patient data);
	bool remove  ();
	bool empty   ( void );
	bool deleted ( void );

    friend class HashTable;
	friend bool operator==(HashTableNode p1, HashTableNode p2);

};


class HashTable 
{
private:
	int N = 2500;
	HashTableNode* segment = new HashTableNode[2500];
	//HashTableNode segment[2500];

	bool correct_key       (HashTableNode data);
	int  get_hash          (HashTableNode data);
	int  get_hash_conflict (HashTableNode data);

public:
	bool insert	  (HashTableNode data);
	bool remove   (HashTableNode data);
	int  find_key (HashTableNode data);
	void print    (int from = 0, int to = 2500);

	friend class HashTableNode;
};

