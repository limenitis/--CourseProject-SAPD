#include ".\..\headers\AVLTree.h"
#include ".\..\headers\str-tools.h"
#include ".\..\headers\SimpleLogs.h"
#include <iostream>
#include <iomanip>
using namespace std;

AVL_Node::AVL_Node(Doctor doc)
{
	key =  doc;
	right = nullptr;
    left  = nullptr;
    h = 1;
}

AVL_Node::AVL_Node(AVL_Node* data)
{
	key   = data->key;
    right = data->right;
    left  = data->left;
    h     = data->h;
}

// конструктор
AVLTree::AVLTree()
{
	root = nullptr;
	count_elements = 0;
}

// деструктор
AVLTree::~AVLTree()
{
}

// вставка в дерево
bool AVLTree::insert(AVL_Node node)
{
	if( find(node) == nullptr ) // element not found => insert into tree
	{
		root = insert(root, &node);
		count_elements += 1;
		log_info("AVLTree", "insert", "true");
		return true;
	}
	else
	{
		log_error("AVLTree", "insert", "The key is already in the tree. The tree must consist of unique keys ");
		return false;
	}
}

AVL_Node* AVLTree::insert(AVL_Node* node, AVL_Node* new_node)
{
	if (node) { log_info("AVLTree", "insert", "node = " << node->key.get_doctor_name() ); }
	if (node == nullptr) 
	{
		return new AVL_Node(new_node);
	}
	if (new_node->key < node->key)
	{
		node->left = insert(node->left, new_node);
	}
	else
	{
		node->right = insert(node->right, new_node);
	}

	return balance(node); //балансировка текущего узла
}

// удаляем узел
bool AVLTree::remove (AVL_Node node)
{
	bool success = false;
	root = remove(root, &node, success);

	return success;
}

AVL_Node* AVLTree::remove(AVL_Node* node, AVL_Node* remove_node, bool &success)
{
	if (node) { log_info("AVLTree", "remove", "node = " << node->key.get_doctor_name() ); }

	if (node == nullptr)
	{
		return 0;
	}

	if (remove_node->key < node->key)
	{
		node->left = remove(node->left, remove_node, success);
	}
	else if (remove_node->key > node->key)
	{
		node->right = remove(node->right, remove_node, success);
	}
	else if (remove_node->key == node->key)
	{
		AVL_Node* q = node->left; 
		AVL_Node* r = node->right;
		delete node; // удаляем наш узел
		count_elements -= 1;
		success = true;

		if (r == nullptr) { return q; }

		AVL_Node* min = findMin(r); // ищем минимальный в правом поддереве
		min->right = removeMin(r);
		min->left = q;
		// cout << "Узел успешно удален." << endl;
		return balance(min);
	}

	return balance(node); // проверяем балансировку
}

AVL_Node* AVLTree::find(AVL_Node node)
{
	return find(root, &node);
}

AVL_Node* AVLTree::find(AVL_Node* node, AVL_Node* find_node)
{
	if (node) { log_info( "AVLTree", "find", "node = " << node->key.get_doctor_name() ); }

	if(node)
	{
		if (node->key > find_node->key) 
		{ 
			log_info( "AVLTree", "find", "walk left");
			return find(node->left, find_node);
		}
		else if (node->key < find_node->key) 
		{
			log_info( "AVLTree", "find", "walk rigth");
			return find(node->right, find_node);
		}
		else if (find_node->key == node->key)
		{
			log_info( "AVLTree", "find", "true");
			return node;
		}
		else
		{
			log_error( "AVLTree", "find", "false");
			return nullptr;
		}
	}
	else
	{
		log_error( "AVLTree", "find", "false");
		return nullptr;
	}
}

/**
 * @brief print elements in tree format
 * 
 */
void AVLTree::print()
{
	cout << endl;
	print(root, 7);
	cout << endl;
	cout << "count nodes : " << this->size() << endl;
	cout << endl;
}

// вывод дерева на экран
void AVLTree::print(AVL_Node* p, int len_space)
{
	if (p)
	{
		print(p->right, len_space + 7 + p->key.get_doctor_name().size()-1);
		for (int i = 0; i <= len_space; i++) cout << " ";
		cout << *p << endl;
		print(p->left, len_space + 7 + p->key.get_doctor_name().size()-1);
	}
}

std::ostream&  operator<< (std::ostream&  out,  AVL_Node &obj)
{
	out.setf(ios::left);
	out << setw(30) << obj.key.get_doctor_name() + "------|";

	return out;
}

/**
 * @brief print AVL_Node 
 * 
 * @param node - AVL_Node in AVLTree
 */
void AVLTree::print(AVL_Node node)
{
	cout.setf(ios::left);
	cout << endl << endl;
	auto element = find(node);

	cout << "/ ---------------------------------------------------------------------- \\ "      << endl;
	cout << "| ::::::::::::::::::::::::::::::: Doctor ::::::::::::::::::::::::::::::: |  "      << endl;
	if(element)
	{
		// cout.setf(ios::left);
		cout << "+ ---------------- + --------------------------------------------------- +  "      << endl;
		cout << "|  Doctor name     |  " << setw(49) << element->key.get_doctor_name()    << "  | " << endl;
		cout << "+ ---------------- + --------------------------------------------------- +  "      << endl;
		cout << "|  Specialization  |  " << setw(49) << element->key.get_specialization() << "  | " << endl;
		cout << "+ ---------------- + --------------------------------------------------- +  "      << endl;
		cout << "|  Cabinet         |  " << setw(49) << element->key.get_cabinet_number() << "  | " << endl;
		cout << "+ ---------------- + --------------------------------------------------- +  "      << endl;
		cout << "|  Schedule        |  " << setw(49) << element->key.get_schedule().get_schedule()  << "  | " << endl;
	}
	else
	{
		cout << "+ ---------------------------------------------------------------------- +  "      << endl;
		cout << "| ::::::::::::::::::::::::::::::: Empty :::::::::::::::::::::::::::::::: |  "      << endl;
	}
	cout << "\\ ---------------------------------------------------------------------- / "      << endl << endl;
}

/**
 * @brief print elements in list format
 * 
 */
void AVLTree::print_list( void )
{
	print_list(root, true);
	cout << "\\ ---------------------------------------------------------------------------- / " << endl << endl;
}

void AVLTree::print_list(AVL_Node* node, bool print_head = 0)
{
	cout.setf(ios::left);

	if (print_head)
	{
		cout << endl;
		cout <<  "/ ---------------------------------------------------------------------------- \\" << endl;
		cout <<  "| ::::::::::::::::::::::::::::::::: Doctors :::::::::::::::::::::::::::::::::: | " << endl;
		cout <<  "+ ----------------------- + ------------------------- + ------- + ------------ + " << endl;
		cout <<  "|  Specialization         |        Doctor name        | Cabinet |   Schedule   | " << endl;
		// cout <<  "+ ----------------------- + ------------------------- + ------- + ------------ + " << endl;
	}

	if (node)
	{
		cout <<  "+ ----------------------- + ------------------------- + ------- + ------------ + " << endl;
		// cout << "|" <<
		cout <<
		          "|  " << setw(21) << node->key.get_specialization()          << 
				"  |  " << setw(23) << node->key.get_doctor_name()             << 
				"  |  " << setw( 5) << node->key.get_cabinet_number()          << 
				"  |  " << setw(10) << node->key.get_schedule().get_schedule() << 
		         " | "   << endl;
		print_list(node->right);
		print_list(node->left);
	}
}

// количество элементов в дереве
int AVLTree::size() 
{ 
	return count_elements; 
}

AVL_Node* AVLTree::removeMin(AVL_Node* p)
{
	// if (p->left == 0)
	if (p->left == nullptr)
	{
		return p->right;
	}
	else
	{
		p->left = removeMin(p->left);
		return balance(p);
	}
}

// ищем минимальный узел
AVL_Node* AVLTree::findMin(AVL_Node* p)
{
	if (p->left != nullptr)
	{
		return findMin(p->left);
	}
	else
	{
		return p;
	}
}

// балансировка
AVL_Node* AVLTree::balance(AVL_Node* p)
{
	log_info( "AVLTree", "balance", "balance around " << p->key.get_doctor_name() );

	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
		{
			p->right = rotateright(p->right);
		}
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
		{
			p->left = rotateleft(p->left);
		}
		return rotateright(p);
	}

	log_info( "AVLTree", "balance", "balancing is not necessary" );
	return p; // балансировка не нужна
}

// поворот вправо
AVL_Node* AVLTree::rotateright(AVL_Node* p)
{
	log_info( "AVLTree", "rotateright", "around " << p->key.get_doctor_name() );

	AVL_Node* q = p->left; 	  // выбор левого поддерева
	if (!q) return p; 	      // если его нет, возвращаем текущий корень

	p->left = q->right;       // переопределяем левый указатель существующего корня
	q->right = p; 		      // устанавливаем правый указатель нового узла на прежний корень
	q->h = p->h; 		      // устанавливаем высоту нового дерева

	fixheight(p); 		      // вычисляем высоту нового поддерева p
	fixheight(q); 		      // вычисляем высоту нового поддерева q

	return q; 			      // возвращаем значение нового корня
}

// поворот влево
AVL_Node* AVLTree::rotateleft(AVL_Node* q)
{
	log_info( "AVLTree", "rotateleft", "around " << q->key.get_doctor_name() );

	AVL_Node* p = q->right;
	if (!p) return q;

	q->right = p->left;
	p->left = q;
	p->h = q->h;

	fixheight(q);
	fixheight(p);

	return p;
}

// ищем значение height
void AVLTree::fixheight(AVL_Node* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->h = (hl > hr ? hl : hr) + 1;
}

// для рассчета высоты
int AVLTree::height(AVL_Node* p)
{
	if (p != nullptr)
	{
		return p->h;
	}
	else
	{
		return 0;
	}
}

// вычисялем баланс-фактор
int AVLTree::bfactor(AVL_Node* p)
{
	return height(p->right) - height(p->left);
}

// вычисляем высоту дерева
int AVLTree::max_depth(AVL_Node* AVL_node)
{
	if (AVL_node == nullptr)
	{
		return 0;
	}
	else
	{
		// вычисляем глубину каждого поддерева
		int lDepth = max_depth(AVL_node->left);
		int rDepth = max_depth(AVL_node->right);

		// возвращаем наибольщую высоту
		if (lDepth > rDepth)
		{
			return(lDepth + 1);
		}
		else
		{
			return(rDepth + 1);
		}
	}
}

