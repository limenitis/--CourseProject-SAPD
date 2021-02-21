#include ".\..\include\HashTable.h"
#include ".\..\include\SimpleLogs.h"
#include ".\..\include\str-tools.h"
#include <iostream>
#include <iomanip>

using namespace std;


HashTableNode::HashTableNode()
{
	delete_data = false;
	empty_data = true; //data = nullptr;
}

bool HashTableNode::intsert (Patient d)
{
	delete_data = false;
	empty_data = false;
	data = d;

	log_info("HashTable", "insert", "true");
	return true;
}

bool HashTableNode::remove ()
{
	delete_data = true;
	empty_data = true;
	//delete data;
	//data = nullptr;

	log_info("HashTable", "remove", "true");
	return true;
}

bool HashTableNode::empty ( void )
{
	if (data.get_year_born() == 0)  { return true;  }
	else                            { return false; }
}

bool HashTableNode::deleted ( void )
{
	return delete_data;
}

bool HashTable::insert(HashTableNode node) 
{
	if (correct_key(node)) 
	{	
		int id = get_hash(node);
		if ( (segment[id].empty()) || (segment[id].deleted()) ) // is empty or delete
		{
			segment[id] = node;
			log_info("HashTable", "insert", "true")
            return true;
        }
		else 
		{
			id = (id + get_hash_conflict(node)) % N;
			
			while (!segment[id].empty() && !segment[id].deleted()) // not empty and not delete
			{
				id = ( id + get_hash_conflict(node) ) % N;
			}

			if ((segment[id].empty()) || (segment[id].deleted()))
			{
				segment[id] = node;
				log_info("HashTable", "insert", "true");
				return true;
			}
			else
			{
				log_error("HashTable", "insert", "false");
				log_error("HashTable", "insert", "busy - ignore element");
				return false;
			}
		}
	}
	else 
	{ 
		log_error("HashTable", "insert", "false");
		log_error("HashTable", "insert", "key don't correct");
		return false;
	}
}

bool HashTable::remove(HashTableNode node) 
{
	if (correct_key(node))
	{
		int pos = find_key(node);

		if (pos == -1)
		{
			log_error("HashTable", "remove", "key don't found");
		}
		else 
		{
			log_info("HashTable", "remove", "key found");
			return segment[pos].remove();
		}
	}
	else 
	{
		log_error("HashTable", "remove", "key don't correct");
		return false;
	}
}

int HashTable::find_key(HashTableNode node)
{
	int id = get_hash(node);

	while ( !(segment[id] == node) && !segment[id].empty() ) 
	{
		id = (id + get_hash_conflict(node)) % N;
	}

	if (segment[id] == node)
	{
		log_info("HashTable", "find_key", "true");
		return id;
	}
	else
	{
		log_info("HashTable", "find_key", "false");
		return -1;
	}
}

bool HashTable::correct_key(HashTableNode node)
{
	// check to uniq

	return true;
}

int HashTable::get_hash(HashTableNode node)
{
	char* key = node.data.get_reg_num().get_reg();

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

int HashTable::get_hash_conflict(HashTableNode node) 
{
	char* key = node.data.get_reg_num().get_reg();

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

void HashTable::print(int from, int to)
{
	if ( (0 <= from) && (to > N) ) { cout << "[print] : id don't correct \n"; return; }

	cout << endl << endl;
	cout <<  "/ -------------------------------------------------------------------------------------------- \\ " << endl;
	cout <<  "| ::::::::::::::::::::::::::::::::::::::::: Patients ::::::::::::::::::::::::::::::::::::::::: |  " << endl;
	cout <<  "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
	cout <<  "|      id       |  Registration number  |               Patient name               | Year born |  " << endl;

	for (int i = from; i < to; i++)
	{
		if (!segment[i].empty()) {
			cout <<  "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
			cout.setf(ios::left);
			cout << "|  "
			<< setw(12) << i 											<< " |  " 
			<< setw(20) << segment[i].data.get_reg_num().get_reg()		<< " |  " 
			<< setw(39) << segment[i].data.get_name()					<< " |  " 
			<< setw(8)  << segment[i].data.get_year_born()	 			<< " |  " 
			<< endl;
		}
	}

	cout << "\\ -------------------------------------------------------------------------------------------- /  " << endl;
	cout << endl << endl;
}



bool operator==(HashTableNode p1, HashTableNode p2)
{
	return compare_str_equal(p1.data.get_reg_num().get_reg(), p2.data.get_reg_num().get_reg());
}

