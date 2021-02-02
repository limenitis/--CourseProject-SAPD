#include "AVLTree.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// конструктор
AVLTreeClass::AVLTreeClass()
{
	root = nullptr;
	count_elements = 0;
}

// деструктор
AVLTreeClass::~AVLTreeClass()
{
	// пройти дерево и собрать адреса, а затем удалить (почистить) эти адреса
}

// вставка в дерево
void AVLTreeClass::insert(Data d)
{
	root = insert(root, d);
	count_elements += 1;
}

AVL_Node* AVLTreeClass::insert(AVL_Node* p, Data d)
{
	if (p == nullptr) 
	{
		return new AVL_Node(d);
	}
	if (d.key < p->data.key)
	{
		p->left = insert(p->left, d.key);
	}
	else
	{
		p->right = insert(p->right, d.key);
	}

	return balance(p); //балансировка текущего узла
}

// удаляем узел
bool AVLTreeClass::remove (Data d)
{
	bool success = false;
	root = remove(root, d, success);

	return success;
}

AVL_Node* AVLTreeClass::remove(AVL_Node* p, Data d, bool &success)
{
	if (p == nullptr)
	{
		return 0;
	}
	if (d.key < p->data.key)
		p->left = remove(p->left, d, success);
	else if (d.key > p->data.key)
		p->right = remove(p->right, d, success);
	else // когда k==p->data
	{
		AVL_Node* q = p->left; 
		AVL_Node* r = p->right;
		delete p; // удаляем наш узел
		count_elements -= 1;
		success = true;

		if (r == nullptr)

			return q;

		AVL_Node* min = findMin(r); // ищем минимальный в правом поддереве
		min->right = removeMin(r);
		min->left = q;
		// cout << "Узел успешно удален." << endl;
		return balance(min);
	}

	return balance(p); // проверяем балансировку
}

AVL_Node* AVLTreeClass::find(Data d)
{
	return find(root, d);
}

AVL_Node* AVLTreeClass::find(AVL_Node* p, Data d)
{
	if(p)
	{
		if (p->data.key >  d.key) 
		{ 
			if (find(p->left,  d.key) == nullptr) 
			{
				return nullptr; 
			}
		}
		else if (p->data.key == d.key) 
		{
			return p;
		}
		else
		{
			if (find(p->right, d.key) == nullptr) 
			{
				return nullptr; 
			}
		}
	}
	else
	{
		return nullptr;
	}
}

void AVLTreeClass::print()
{
	print(root, 0);
}

// вывод дерева на экран
void AVLTreeClass::print(AVL_Node* p, int l)
{
	if (p)
	{
		print(p->right, l + 1);
		for (int i = 0; i <= l; i++) cout << "           ";
		cout << p->data.key << "|-----------" << endl;
		print(p->left, l + 1);
	}
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


