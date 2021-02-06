#pragma once
#include ".\..\include\HashTable.h"
#include <iostream>

using namespace std;

bool HashTable::insert(char* key) 
{
	if (correct_key(key)) 
	{	
		int c = 0;
		int id = get_hash(key);
		if ( (segment[id]) || (segment[id] == "<delete>") ) // is empty
		{
			segment[id] = key;
            return true;
        }
		else 
		{
			id = (id + get_hash_conflict(key)) % N;
			while ( ((segment[id][0] != "") && (segment[id][0] != "<delete>")) )
			{
				id = ( id + get_hash_conflict(key) ) % N;
			}

			if ((segment[id] == "") || (segment[id] == "<delete>"))
			{
				segment[id] = key;
			}
			else
			{
				cout << "[insert] : failure : \n d busy : ignore element"; 
			}
		}
	}
	else 
	{ 
		cout << "[insert] : key don't \n orrect"; 
	}
}

bool HashTable::remove(char* key) 
{
	if (correct_key(key))
	{
		int id = get_hash(key);
		int pos = find_key(key);

		if (pos == -1)
		{
			cout << "[remove] key don't \n ound";
		}
		else { segment[pos] = "<delete>"; return true; }
	}
	else { cout << "[remove] key don't correct \n "; }
}

int HashTable::find_key(char* key)
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
	else { cout << "[find key] key don't correct \n"; }
}

bool HashTable::correct_key(char* key)
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

int HashTable::get_hash(char* key)
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

int HashTable::get_hash_conflict(char* key) 
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

void HashTable::print(int from = 0, int to = 2500)
{
	if (0 < from && to > N) { cout << "[print] : id don't correct \n"; return; }

	int c = 0;
	for (int i = from; i < to; i++)
	{
        // cout
	}
}
