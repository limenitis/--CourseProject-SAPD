#pragma once
#include ".\..\include\HashTable.h"
#include ".\..\include\str-tools.h"
#include <iostream>

using namespace std;

HashTableNode::HashTableNode()
{
	delete_data = false;
	data = nullptr;
	key  = nullptr;
}

bool HashTableNode::intsert (Patient* d)
{
	delete_data = false;
	data = d;
	key  = d->get_reg_num();
}

bool HashTableNode::remove ()
{
	delete_data = true;
	delete data;
	data = nullptr;
	key  = nullptr;
}

bool HashTableNode::empty ( void )
{
	return data == nullptr;
}

bool HashTableNode::deleted ( void )
{
	return delete_data;
}

auto HashTableNode::get_key ( void )
{
	return key;
}


bool HashTable::insert(HashTableNode* node) 
{
	if (correct_key(node)) 
	{	
		int c = 0;
		int id = get_hash(node);
		if ( (segment[id]->empty()) || (segment[id]->deleted()) ) // is empty or delete
		{
			segment[id] = node;
            return true;
        }
		else 
		{
			id = (id + get_hash_conflict(node)) % N;
			
			while ( ((!segment[id]->empty()) && (!segment[id]->deleted())) ) // not empty and not delete
			{
				id = ( id + get_hash_conflict(node) ) % N;
			}

			if ((segment[id]->empty()) || (segment[id]->deleted()))
			{
				segment[id] = node;
				return true;
			}
			else
			{
				cout << "[insert] : failure : \n busy : ignore element";
				return false;
			}
		}
	}
	else 
	{ 
		cout << "[insert] : key don't \n correct";
		return false;
	}
}

bool HashTable::remove(HashTableNode* node) 
{
	if (correct_key(node))
	{
		int id = get_hash(node);
		int pos = find_key(node);

		if (pos == -1)
		{
			cout << "[remove] key don't \n ound";
		}
		else { segment[pos]->deleted(); return true; }
	}
	else { cout << "[remove] key don't correct \n "; }
}

int HashTable::find_key(HashTableNode* node)
{
	if (correct_key(node))
	{
		int id = get_hash(node);
		int stop_id = id;

		while ( segment[id] != node) 
		{
			id = (id + get_hash_conflict(node)) % N;
			if (id == stop_id) { break; }
		}

		if (segment[id] == node) { return id; }
		else { return -1; } // err 
	}
	else { cout << "[find key] key don't correct \n"; }
}

bool HashTable::correct_key(HashTableNode* node)
{
	// if (node.size() != 6) { return false; }

	// if (  is_char  (key[0])
	// &&    is_num_c (key[1]) 
	// &&    is_num_c (key[2])
	// &&	  is_num_c (key[3])
	// &&    is_char  (key[4])
	// &&    is_char  (key[5]) ) { return true; }

	// else { return false; }



	return true;
}

int HashTable::get_hash(HashTableNode* node)
{
	char* key = node->get_key().get_reg();

	if (correct_key(node))
	{
		int sum_key = 0;
		for (int i = 0; i < len_str(key); i++) 
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

int HashTable::get_hash_conflict(HashTableNode* node) 
{
	char* key = node->get_key().get_reg();

	if (correct_key(node))
	{
		int sum_key = 0;
		for (int i = 0; i < len_str(key); i++)
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
	if ( (0 <= from) && (to > N) ) { cout << "[print] : id don't correct \n"; return; }

	int c = 0;
	for (int i = from; i < to; i++)
	{
        // cout
	}
}

