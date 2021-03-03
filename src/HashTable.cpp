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
}


HashTableNode::HashTableNode(const HashTableNode& obj)
{
    log_warning("HashTableNode", "HashTableNode", "copy constructor work ");
    log_warning("HashTableNode", "HashTableNode", "copy from " << &obj);
	log_warning("HashTableNode", "HashTableNode", "copy to   " << this);

	if (obj.data)
	{
		this->data = new Patient{ *obj.data };
	}
	else
	{
		this->data = nullptr;
	}
	this->delete_data = obj.delete_data;
}


HashTableNode::~HashTableNode()
{
	if (data) delete data;
	data = nullptr;
}


bool HashTableNode::intsert (const Patient &d)
{
	delete_data = false;

	if(data) delete data;
	data = new Patient{d};

	log_info("HashTableNode", "insert", "true");
	return true;
}


bool HashTableNode::remove ()
{
	delete_data = true;
	if (data) delete data;
	data = nullptr;

	log_info("HashTableNode", "remove", "true");
	return true;
}


bool HashTableNode::deleted ( void )
{
	return delete_data;
}


HashTable::HashTable()
{
	table_size = 7;
	count_elements = 0;
	table = new HashTableNode * [table_size] {nullptr};
}


HashTable::HashTable(int size)
{
	table_size = size;
	count_elements = 0;
	table = new HashTableNode * [table_size] {nullptr};
}


HashTable::~HashTable()
{
	for (int id = 0; id < table_size; id++)
	{
		if (table[id] != nullptr) 
		{
			delete table[id];
		}
	}
	table_size = 0;
	delete[] table;
}


bool HashTable::resize()
{
	log_info("HashTable", "resize", "start");

	//create new
	int new_table_size = (int)(table_size * 2);
	HashTableNode** new_table = new HashTableNode * [new_table_size] {nullptr};

	HashTableNode **old_table = table;
	int old_table_size = table_size;
	this->table = new_table;
	this->table_size = new_table_size;

	// copy
	for (int id = 0; id < old_table_size; id++)		
	{
		if(old_table[id] != nullptr)
		{
			this->insert(*old_table[id]);
			count_elements -= 1;
		}
	}

	//delete old
	delete[] old_table;

	log_info("HashTable", "resize", "new size = " << table_size);
	log_info("HashTable", "resize", "end");

	return true;
}


bool HashTable::insert(const HashTableNode &node) 
{
	if (correct_key(node)) 
	{
		if (table_size - count_elements < 5)
		{
			resize();
		}

		int id = get_hash(node);
		if (table[id] == nullptr) // is empty 
		{
			table[id] = new HashTableNode{node};
			count_elements += 1;
			log_info("HashTable", "insert", "true");
			log_info("HashTable", "insert", "fill percent = " << 100 * count_elements/table_size << "%" );
			log_info("HashTable", "insert", "count_elements = " << count_elements);
			return true;
        }
		else if ( table[id]->deleted() ) // is delete
		{
			table[id] = new HashTableNode{node};
			count_elements += 1;
			log_info("HashTable", "insert", "true");
			log_info("HashTable", "insert", "fill percent = " << 100 * count_elements/table_size << "%" );
			log_info("HashTable", "insert", "count_elements = " << count_elements);
			return true;
		}
		else 
		{
			while (table[id] != nullptr && !table[id]->deleted()) // not empty and not delete
			{
				id = ( id + get_hash_conflict(node) ) % table_size;
			}

			if ( table[id] == nullptr )
			{
				table[id] = new HashTableNode{node};
				count_elements += 1;
				log_info("HashTable", "insert", "true");
				log_info("HashTable", "insert", "fill percent = " << 100 * count_elements/table_size << "%" );
				log_info("HashTable", "insert", "count_elements = " << count_elements);
				return true;
			}
			else if ( table[id]->deleted() )
			{
				table[id] = new HashTableNode{node};
				count_elements += 1;
				log_info("HashTable", "insert", "true");
				log_info("HashTable", "insert", "fill percent = " << 100 * count_elements/table_size << "%" );
				log_info("HashTable", "insert", "count_elements = " << count_elements);
				return true;
			}
			else
			{
				log_error("HashTable", "insert", "false");
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
	int pos = find_key(node);

	if (pos == -1)
	{
		log_error("HashTable", "remove", "key don't found");
		return false;
	}
	else 
	{
		log_info("HashTable", "remove", "key found");
		if ( table[pos]->remove() )
		{
			count_elements -= 1;
			log_info("HashTable", "remove", "fill percent = " << 100 * count_elements/table_size << "%" );
			log_info("HashTable", "remove", "fill count_element = " << count_elements);
			return true;
		}
		else
		{
			log_error("HashTable", "remove", "false");
			return false;
		}
	}
}


int HashTable::find_key(const HashTableNode &node)
{
	int id = get_hash(node);

	while ( table[id] != nullptr )
	{
		if ( table[id]->deleted() != true )
		{
			if (*table[id] == node)
			{
				log_info("HashTable", "find_key", "return " << id);
				return id;
			}
		}
		id = (id + get_hash_conflict(node)) % table_size;
	}
	log_error("HashTable", "find_key", "return " << "error : key don't found" );
	return -1;
}

int HashTable::find_by_name (const HashTableNode &node)
{
	// int id = get_hash(node);
	int id = 0;

	while(id < table_size)
	{
		if ( table[id] != nullptr )
		{
			if ( table[id]->deleted() != true )
			{
				if (table[id]->data->get_name() == node.data->get_name())
				{
					log_info("HashTable", "find_key", "return " << id);
					return id;
				}
			}
			// id = (id + get_hash_conflict(node)) % table_size;
		}
 		id +=1;
	}
	log_error("HashTable", "find_key", "return " << "error : key don't found" );
	return -1;
}


bool HashTable::correct_key(const HashTableNode &node)
{
	if( find_key(node) == -1 ) // don't found
	{
		string str = "00-0000000";
		if ( !compare_str_equal(const_cast<char*>(node.data->get_reg()->get_reg().c_str()), 
								const_cast<char*>(str.c_str())) )
		{
			log_info("HashTable", "correct_key", "true");
			return true;
		}
		log_error("HashTable", "correct_key", "false");
		log_error("HashTable", "correct_key", "key 00-0000000");
		return false;
	}
	else
	{
		log_error("HashTable", "correct_key", "false");
		log_error("HashTable", "correct_key", "key don't found");
		return false;
	}
}


int HashTable::get_hash(const HashTableNode &node)
{
	string key = node.data->get_reg()->get_reg();

	// int sum_key = 0;
	// int len = len_str(key);
	// for (int i = 0; i < len; i++) 
	// {
	// 	// sum_key += key[i] * pow(2, i);
	// }

	int sum_key = key.size();

	if (sum_key < 0) 
	{
		log_error("HashTable", "get_hash", "false");
		log_error("HashTable", "get_hash", "sum key less zero");
		return -1;
	}
	else 
	{
		log_info("HashTable", "get_hash", "return " << sum_key % table_size );
		return sum_key % table_size; 
	}
}


int HashTable::get_hash_conflict(const HashTableNode &node) 
{
	int sum_key = 101;
	// int sum_key = 3;
	log_info("HashTable", "get_hash_conflict", "return " << sum_key % table_size );
	return sum_key % table_size;
}

/**
 * @brief print full table
 * 
 */
void HashTable::print (void)
{
	print(0, table_size);
}


/**
 * @brief print part of the HashTable
 * 
 * @param from - start  number id
 * @param to   - finish number id
 */
void HashTable::print(int from, int to)
{
	if (to == 0) { to = table_size; }
	if ( (0 <= from) && (to > table_size) ) { cout << "[print] : id don't correct \n"; return; }

	log_info("HashTable", "print", "range");
	log_info("HashTable", "print", "from " << from);
	log_info("HashTable", "print", "to   " << to);

	cout << endl << endl;
	cout <<  "/ -------------------------------------------------------------------------------------------- \\ " << endl;
	cout <<  "| ::::::::::::::::::::::::::::::::::::::::: Patients ::::::::::::::::::::::::::::::::::::::::: |  " << endl;
	cout <<  "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
	cout <<  "|      id       |  Registration number  |               Patient name               | Year born |  " << endl;

	for (int id = from; id < to; id++)
	{
		if (table[id] != nullptr) 
		{
			if(table[id]->deleted() != true)
			{
				cout << "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
				cout.setf(ios::left);
				cout << "|  "
				<< setw(12) << id 											<< " |  " 
				<< setw(20) << table[id]->data->get_reg()->get_reg() 		<< " |  " 
				<< setw(39) << table[id]->data->get_name()					<< " |  " 
				<< setw(8)  << table[id]->data->get_year_born()	 			<< " |  " 
				<< endl;
			}
			log_warning("HashTable", "print", "element addres " << table[id]);
		}
	}

	cout << "\\ -------------------------------------------------------------------------------------------- /  " << endl;
	cout << endl << endl;
}

/**
 * @brief print the interval
 * 
 * @param condition - function with condition
 */
void HashTable::print ( bool condition(int id) )
{
	cout << endl << endl;
	cout <<  "/ -------------------------------------------------------------------------------------------- \\ " << endl;
	cout <<  "| ::::::::::::::::::::::::::::::::::::::::: Patients ::::::::::::::::::::::::::::::::::::::::: |  " << endl;
	cout <<  "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
	cout <<  "|      id       |  Registration number  |               Patient name               | Year born |  " << endl;

	for (int id = 0; id < table_size; id++)
	{
		if (table[id] != nullptr) 
		{
			if (table[id]->deleted() != true)
			{
				if(condition(id))
				{
					cout << "+ ------------- + --------------------- + ---------------------------------------- + --------- +  " << endl;
					cout.setf(ios::left);
					cout << "|  "
					<< setw(12) << id 											<< " |  " 
					<< setw(20) << table[id]->data->get_reg()->get_reg() 		<< " |  " 
					<< setw(39) << table[id]->data->get_name()					<< " |  " 
					<< setw(8)  << table[id]->data->get_year_born()	 			<< " |  " 
					<< endl;
					log_warning("HashTable", "print", "element addres " << table[id]);
				}
			}
		}
	}

	cout << "\\ -------------------------------------------------------------------------------------------- /  " << endl;
	cout << endl << endl;
}

/**
 * @brief print detailed information about id
 * 
 * @param id - id in HashTable
 */
void HashTable::print (int id)
{
	cout << endl << endl;
	if(table[id])
	{
		cout.setf(ios::left);
		cout <<  "/ --------------------------------------------------------------------------------- \\ " << endl;
		cout <<  "| :::::::::::::::::::::::::::::::::::: Patient :::::::::::::::::::::::::::::::::::: |  " << endl;
		cout <<  "+ --------------------- + --------------------------------------------------------- +  " << endl;
		cout <<  "|  Registration number  |  " << setw(57) << table[id]->data->get_reg()->get_reg() << "|" << endl;
		cout <<  "+ --------------------- + --------------------------------------------------------- +  " << endl;
		cout <<  "|  Patient name         |  " << setw(57) << table[id]->data->get_name() <<         "|"   << endl;
		cout <<  "+ --------------------- + --------------------------------------------------------- +  " << endl;
		cout <<  "|  Work place           |  " << setw(57) << table[id]->data->get_work() <<         "|"   << endl;
		cout <<  "+ --------------------- + --------------------------------------------------------- +  " << endl;
		cout <<  "|  Addres               |  " << setw(57) << table[id]->data->get_addres() <<       "|"   << endl;
		cout <<  "+ --------------------- + --------------------------------------------------------- +  " << endl;
		cout <<  "|  Year born            |  " << setw(57) << table[id]->data->get_year_born() <<    "|"   << endl;
		cout << "\\ --------------------------------------------------------------------------------- /  " << endl;
	}
	else
	{
		cout << "Empty id" << endl;
	}
	cout << endl << endl;
}


/**
 * @brief clear data in HashTable 
 * 
 * @return true  - successful clear
 * @return false - unsuccessful clear
 */
bool HashTable::clear( void )
{
	for (int id = 0; id < table_size; id++)
	{
		if (table[id] != nullptr) 
		{
			table[id]->remove();
		}
	}
	count_elements = 0;

	log_info("HashTable", "clear", "true")
	return true;
}


bool operator==(const HashTableNode &p1, const HashTableNode &p2)
{
	return compare_str_equal(const_cast<char*>(p1.data->get_reg()->get_reg().c_str()), 
							 const_cast<char*>(p2.data->get_reg()->get_reg().c_str()));
}
