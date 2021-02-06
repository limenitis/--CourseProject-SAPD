#pragma once
#include <iostream>
//#include <vector>

using namespace std;

class Data
{
public:
    int key;

    Data()
    {
        key = 0;
    }
    Data(int k)
    {
        key = k;
    }
};

// поля данных
struct AVL_Node
{
    Data data;
    AVL_Node* right;
    AVL_Node* left;
    int h;

    AVL_Node(Data d)
    {
        data = d;
        right = nullptr;
        left  = nullptr;
        h = 1;
    }
};

class AVLTreeClass
{
private:
    AVL_Node  *root;                   // корень
    int count_elements;                // количество элементов в дереве

    AVL_Node  *insert       (AVL_Node*, Data);        // вставка данных в дерево с корнем p
    AVL_Node  *remove       (AVL_Node*, Data, bool&); // функция удаления узла
    AVL_Node  *find 		(AVL_Node*, Data);        // поиск узла с искомым значением
    AVL_Node  *removeMin	(AVL_Node*); 	          // удаление узла с минимальным значением
    AVL_Node  *findMin		(AVL_Node*); 	          // поиск узла с минимальным значением
    AVL_Node  *balance		(AVL_Node*); 	          // балансировка узла p
    AVL_Node  *rotateright	(AVL_Node* p); 	          // правый поворот вокруг узла p
    AVL_Node  *rotateleft	(AVL_Node* q); 	          // левый поворот вокруг узла q
    void   fixheight	    (AVL_Node*); 	          // смотрим значение height узла
    int    height           (AVL_Node*);              // высота узла
    int    bfactor          (AVL_Node*);              // баланс-фактор
    int    max_depth        (AVL_Node*);              // смотрим значение высоты всего дерева
    void   print		    (AVL_Node*, int);         // вывод дерева на экран с обходом в высоту

public:
    AVLTreeClass();    // конструктор
    ~AVLTreeClass();   // деструктор

    void        insert		(Data);            // вставка данных в дерево с корнем p
    bool        remove      (Data);            // функция удаления узла
    AVL_Node*   find 	    (Data);            // поиск узла с искомым значением
    void        print		(void);            // вывод дерева на экран с обходом в высоту
    int         count       (void);            // считает количество вершин в дереве

};
