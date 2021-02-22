﻿#pragma once
#include <iostream>
#include ".\..\include\Patient.h"
#include ".\..\include\RegistrationNumber.h"

using namespace std;

class HashTableNode
{
private:
	Patient *data;
	bool delete_data;


public:
	HashTableNode();
	HashTableNode(const HashTableNode& obj);
	~HashTableNode();

	bool intsert (Patient &data);
	bool remove  ();
	bool deleted ( void );

    friend class HashTable;
	friend bool operator==(HashTableNode p1, HashTableNode p2);
};


class HashTable 
{
private:
	int table_size;
	int count_elements;
	HashTableNode** table;

	bool resize();
	bool correct_key       (const HashTableNode &data);
	int  get_hash          (const HashTableNode &data);
	int  get_hash_conflict (const HashTableNode &data);

public:
	HashTable();
	HashTable(int size);
	~HashTable();

	bool insert	  (HashTableNode data);
	bool remove   (HashTableNode data);
	int  find_key (const HashTableNode &data);
	void print    (int from = 0, int to = 0);

	friend class HashTableNode;
};

