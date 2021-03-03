#pragma once
#include <iostream>
#include ".\..\headers\Patient.h"
#include ".\..\headers\RegistrationNumber.h"

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

	bool intsert (const Patient &data);
	bool remove  ();
	bool deleted ( void );

    friend class HashTable;
	friend bool operator==(const HashTableNode &p1, const HashTableNode &p2);
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

	bool insert	  (const HashTableNode &data);
	bool remove   (const HashTableNode &data);
	int  find_key (const HashTableNode &data);

	int  find_by_name (const HashTableNode &data);

	void print    (void);
	void print    (int id);
	void print    (int from, int to);
	void print    (bool condition(int id));

	bool clear ( void );

	friend class HashTableNode;
};

