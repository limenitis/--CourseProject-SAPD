#include ".\..\include\AVLTree.h"
#include ".\..\include\str-tools.h"
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
AVLTreeClass::AVLTreeClass()
{
	root = nullptr;
	count_elements = 0;
}

// деструктор
AVLTreeClass::~AVLTreeClass()
{
	// while (count_elements >= 0)
	// {
	// 	remove(root);
	// }
	
	// пройти дерево и собрать адреса, а затем удалить (почистить) эти адреса
}

// вставка в дерево
void AVLTreeClass::insert(AVL_Node node)
{
	root = insert(root, &node);
	count_elements += 1;
}

AVL_Node* AVLTreeClass::insert(AVL_Node* node, AVL_Node* new_node)
{
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
bool AVLTreeClass::remove (AVL_Node node)
{
	bool success = false;
	root = remove(root, &node, success);

	return success;
}

AVL_Node* AVLTreeClass::remove(AVL_Node* node, AVL_Node* remove_node, bool &success)
{
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
	else // когда node->key == p->data
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

AVL_Node* AVLTreeClass::find(AVL_Node node)
{
	return find(root, &node);
}

AVL_Node* AVLTreeClass::find(AVL_Node* node, AVL_Node* find_node)
{
	if(node)
	{
		if (node->key > find_node->key) 
		{ 
			return find(node->left, find_node);
		}
		else if (node->key < find_node->key) 
		{
			return find(node->right, find_node);
		}
		else  // node->key == find_node->key
		{
			return node;
		}
	}
	else
	{
		return nullptr;
	}
}

void AVLTreeClass::print()
{
	print(root, 7);
}

void AVLTreeClass::print(AVL_Node p)
{
    cout << "Empty implementation" << endl;
}
void AVLTreeClass::print_list(void)
{
    cout << "Empty implementation" << endl;

	this->print();
}

// вывод дерева на экран
void AVLTreeClass::print(AVL_Node* p, int len_spase)
{
	if (p)
	{
		print(p->right, len_spase + 7 + p->key.get_doctor_name().size()-1);
		for (int i = 0; i <= len_spase; i++) cout << " ";
		cout << *p << endl;
		print(p->left, len_spase + 7 + p->key.get_doctor_name().size()-1);
	}
}

std::ostream&  operator<< (std::ostream&  out,  AVL_Node &obj)
{
	out.setf(ios::left);
	out << setw(30) << obj.key.get_doctor_name() + "------|";

	return out;
}

// количество элементов в дереве
int AVLTreeClass::count() 
{ 
	return count_elements; 
}

AVL_Node* AVLTreeClass::removeMin(AVL_Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

// ищем минимальный узел
AVL_Node* AVLTreeClass::findMin(AVL_Node* p)
{
	if (p->left != nullptr)
		return findMin(p->left);
	else
		return p;
}

// балансировка
AVL_Node* AVLTreeClass::balance(AVL_Node* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)

			p->right = rotateright(p->right);

		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)

			p->left = rotateleft(p->left);

		return rotateright(p);
	}
	return p; // балансировка не нужна
}

// поворот вправо
AVL_Node* AVLTreeClass::rotateright(AVL_Node* p)
{
	AVL_Node* q = p->left; 	  // выбор левого поддерева
	if (!q) return p; 	  // если его нет, возвращаем текущий корень
	p->left = q->right;   // переопределяем левый указатель существующего корня
	q->right = p; 		  // устанавливаем правый указатель нового узла на прежний корень
	q->h = p->h; 		  // устанавливаем высоту нового дерева
	fixheight(p); 		  // вычисляем высоту нового поддерева p
	fixheight(q); 		  // вычисляем высоту нового поддерева q
	return q; 			  // возвращаем значение нового корня
}

// поворот влево
AVL_Node* AVLTreeClass::rotateleft(AVL_Node* q)
{
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
void AVLTreeClass::fixheight(AVL_Node* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->h = (hl > hr ? hl : hr) + 1;
}

// для рассчета высоты
int AVLTreeClass::height(AVL_Node* p)
{
	if (p != nullptr)
	{
		return p->h;
	}
	else
		return 0;
}

// вычисялем баланс-фактор
int AVLTreeClass::bfactor(AVL_Node* p)
{
	return height(p->right) - height(p->left);
}

// вычисляем высоту дерева
int AVLTreeClass::max_depth(AVL_Node* AVL_node)
{
	if (AVL_node == nullptr)
		return 0;
	else
	{
		// вычисляем глубину каждого поддерева
		int lDepth = max_depth(AVL_node->left);
		int rDepth = max_depth(AVL_node->right);

		// возвращаем наибольщую высоту
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

