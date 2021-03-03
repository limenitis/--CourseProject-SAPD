#pragma once
#include <iostream>
#include ".\..\include\Doctor.h"
using namespace std;

class AVL_Node
{
private:
    Doctor key;

    AVL_Node* right;
    AVL_Node* left;
    int h;

public:
    // AVL_Node();
    AVL_Node(Doctor data);
    AVL_Node(AVL_Node* data);

    friend class AVLTreeClass;
    friend std::ostream&  operator<< (std::ostream&  out,  AVL_Node &obj);
    // friend std::istream&  operator>> (std::istream&  in,   AVL_Node &obj);
};


class AVLTreeClass
{
private:
    AVL_Node  *root;                   // корень
    int count_elements;                // количество элементов в дереве

    AVL_Node  *insert       (AVL_Node*, AVL_Node*);        // вставка данных в дерево с корнем p
    AVL_Node  *remove       (AVL_Node*, AVL_Node*, bool&); // функция удаления узла
    AVL_Node  *find 		(AVL_Node*, AVL_Node*);        // поиск узла с искомым значением
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

    void        insert		(AVL_Node);        // вставка данных в дерево с корнем p
    bool        remove      (AVL_Node);        // функция удаления узла
    AVL_Node*   find 	    (AVL_Node);        // поиск узла с искомым значением

    void        print       (AVL_Node);        //
    void        print		(void);            //
    void        print_list  (void);            //

    int         count       (void);            // считает количество вершин в дереве
};


