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
	table_size = (int)find_next_prime(size);
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
	//create new
	int new_table_size = (int)find_next_prime((int64_t)table_size * 2); // prime number

	HashTableNode** new_table = new HashTableNode * [new_table_size] {nullptr};

	//copy
	for (int id = 0; id < table_size; id++)		
	{
		if(table[id] != nullptr)
		{
			new_table[id] = new HashTableNode{ *table[id] };
		}
	}

	//delete old
	delete[] table;
	table = new_table;
	table_size = new_table_size;

	log_info("HashTable", "resize", "true");
	log_info("HashTable", "resize", "new size = " << table_size);
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

	while (true)
	{
		if (table[id])
		{
			if (*table[id] == node)
			{
				log_info("HashTable", "find_key", "return " << id);
				return id;
			}
		}

		while ( table[id] != nullptr && table[id]->deleted() )
		{
			if (table[id])
			{
				if (*table[id] == node)
				{
					log_info("HashTable", "find_key", "return " << id );
					return id;
				}
				else
				{
					continue;
				}
			}
			id = (id + get_hash_conflict(node)) % table_size;
		}
		log_error("HashTable", "find_key", "return " << "error : key don't found" );
		return -1;
	}
}

bool HashTable::correct_key(const HashTableNode &node)
{
	if( find_key(node) == -1 ) // don't found
	{
		log_info("HashTable", "correct_key", "true");
		return true;
	}
	else
	{
		log_error("HashTable", "correct_key", "false");
		return false;
	}
}

int HashTable::get_hash(const HashTableNode &node)
{
	char* key = node.data->get_reg()->get_reg();

	int sum_key = 0;
	int len = len_str(key);
	for (int i = 0; i < len; i++) 
	{
		sum_key += key[i] * pow(2, i);
		// sum_key += key[i];
	}

	if (sum_key < 0) 
	{
		log_error("HashTable", "get_hash", "false");
		log_error("HashTable", "get_hash", "sum key less zero");
		return -1;
	}
	else 
	{
		log_info("HashTable", "get_hash", "return " << sum_key % table_size );
		return sum_key % table_size; //? pow(i,n) % n
	}
}

int HashTable::get_hash_conflict(const HashTableNode &node) 
{
	// int sum_key = 333; //! need check
	int sum_key = 3;
	log_info("HashTable", "get_hash_conflict", "return " << sum_key % table_size );
	return sum_key % table_size;
}

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
	return compare_str_equal(p1.data->get_reg()->get_reg(), p2.data->get_reg()->get_reg());
}


bool prime(int64_t n)
{
	int64_t i = 2;
	while (i * i <= n)
	{
		if (n % i == 0) return false;
		i++;
    }
    return true;
}

int64_t find_next_prime(int64_t n)
{
	while (prime(n) == false)
	{
		n += 1;
	}
	return n;
}
