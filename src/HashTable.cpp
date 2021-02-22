#include ".\..\include\HashTable.h"
#include ".\..\include\str-tools.h"
#include ".\..\include\SimpleLogs.h"
#include <iostream>
#include <iomanip>

using namespace std;


HashTableNode::HashTableNode()
{
	data = nullptr;
	delete_data = false;
	empty_data = true; 
}

HashTableNode::HashTableNode(const HashTableNode& obj)
{
	//? check for nullptr
	this->data = obj.data; 
	this->delete_data = obj.delete_data;
	this->empty_data  = obj.empty_data;
}

HashTableNode::~HashTableNode()
{
	delete_data = true;
	empty_data = true;
}

bool HashTableNode::intsert (Patient d)
{
	delete_data = false;
	empty_data = false;

	data = new Patient{d};

	log_info("HashTableNode", "insert", "true");
	return true;
}

bool HashTableNode::remove ()
{
	delete_data = true;
	empty_data = true;
	delete data;
	data = nullptr;

	log_info("HashTableNode", "remove", "true");
	return true;
}

bool HashTableNode::empty ( void )
{
	// if (data == nullptr)  { return true;  }
	// else                  { return false; }
	return empty_data;
}

bool HashTableNode::deleted ( void )
{
	return delete_data;
}

HashTable::HashTable()
{
	table_size = 2500;
	count_elements = 0;
	segment = new HashTableNode[table_size];
}

HashTable::HashTable(int s)
{
	table_size = s;
	count_elements = 0;
	segment = new HashTableNode[s];
}

HashTable::~HashTable()
{
	for (int i = 0; i < table_size; i++)
	{
		if (!segment[i].empty()) 
		{
			segment[i].remove();
		}
	}
	table_size = 0;
	delete[] segment;
}

bool HashTable::resize()
{
	//create new
	int new_table_size = (int)table_size * 1.5;
	HashTableNode *new_segment = new HashTableNode[new_table_size];

	//copy
	for (int id = 0; id < table_size; id++)		
	{
		if(!segment[id].empty())
		{
			new_segment[id] = segment[id];
		}
	}

	//delete old
	delete segment;
	segment = new_segment;
	table_size = new_table_size;

	log_info("HashTable", "resize", "true");
	return true;
}

bool HashTable::insert(HashTableNode node) 
{
	if (correct_key(node)) 
	{	
		int id = get_hash(node);
		if ( (segment[id].empty()) || (segment[id].deleted()) ) // is empty or delete
		{
			segment[id] = node;
			log_info("HashTable", "insert", "true");
			log_info_val("HashTable", "insert", "fill percent = ", (int)count_elements/table_size);
			count_elements += 1;
			return true;
        }
		else 
		{
			id = (id + get_hash_conflict(node)) % table_size;
			
			while (!segment[id].empty() && !segment[id].deleted()) // not empty and not delete
			{
				id = ( id + get_hash_conflict(node) ) % table_size;
			}

			if ((segment[id].empty()) || (segment[id].deleted()))
			{
				segment[id] = node;
				log_info("HashTable", "insert", "true");
				log_info_val("HashTable", "insert", "fill percent = ", (int)count_elements/table_size);
				count_elements += 1;
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

bool HashTable::remove(const HashTableNode &node) 
{
	if (correct_key(node))
	{
		int pos = find_key(node);

		if (pos == -1)
		{
			log_error("HashTable", "remove", "key don't found");
			return false;
		}
		else 
		{
			log_info("HashTable", "remove", "key found");
			if ( segment[pos].remove() )
			{
				log_info_val("HashTable", "remove", "fill percent = ", (int)count_elements/table_size);
				count_elements -= 1;
				return true;
			}
			else
			{
				log_error("HashTable", "remove", "false");
				log_error("HashTable", "remove", "id error : x00001");
				return false;
			}
		}
	}
	else 
	{
		log_error("HashTable", "remove", "false");
		log_error("HashTable", "remove", "key don't correct");
		return false;
	}
}

int HashTable::find_key(const HashTableNode &node)
{
	int id = get_hash(node);

	while ( !(segment[id] == node) && !segment[id].empty() ) 
	{
		id = (id + get_hash_conflict(node)) % table_size;
	}

	if (segment[id] == node)
	{
		log_info("HashTable", "find_key", "true");
		return id;
	}
	else
	{
		log_error("HashTable", "find_key", "false");
		log_error("HashTable", "find_key", "key don't found");
		return -1;
	}
}

bool HashTable::correct_key(const HashTableNode &node)
{
	// check to uniq

	return true;
}

int HashTable::get_hash(const HashTableNode &node)
{
	char* key = node.data->get_reg().get_reg();

	if (correct_key(node))
	{
		int sum_key = 0;
		int len = len_str(key);
		for (int i = 0; i < len; i++) 
		{
			sum_key += key[i] * pow(2, i);
		}

		if (sum_key < 0) { return -1; }
		else { return(sum_key) % table_size; }
	}
	else
	{
		log_error("HashTable", "get_hash", "false");
		log_error("HashTable", "get_hash", "key don't correct");
		return -1;
	}
}

int HashTable::get_hash_conflict(const HashTableNode &node) 
{
	char* key = node.data->get_reg().get_reg();

	if (correct_key(node))
	{
		int sum_key = 0;
		for (int i = 0; i < len_str(key); i++)
		{
			sum_key += key[i] * pow(5, i);
		}

		if (sum_key < 0) { return -1; }
		else { return(sum_key) % table_size; }
	}
	else
	{
		log_error("HashTable", "get_hash_conflict", "false");
		log_error("HashTable", "get_hash_conflict", "key don't correct");		
		return -1;
	}
}

void HashTable::print(int from, int to)
{
	if ( (0 <= from) && (to > table_size) ) { cout << "[print] : id don't correct \n"; return; }

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
			<< setw(20) << segment[i].data->get_reg().get_reg() 		<< " |  " 
			<< setw(39) << segment[i].data->get_name()					<< " |  " 
			<< setw(8)  << segment[i].data->get_year_born()	 			<< " |  " 
			<< endl;
		}
	}

	cout << "\\ -------------------------------------------------------------------------------------------- /  " << endl;
	cout << endl << endl;
}



bool operator==(HashTableNode p1, HashTableNode p2)
{
	return compare_str_equal(p1.data->get_reg().get_reg(), p2.data->get_reg().get_reg());
}
