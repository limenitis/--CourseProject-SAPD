#pragma once
#include <iostream>
#include <fstream>
#include ".\..\include\Direction.h"


class LinkedListNode
{
private:
    Direction data;
    LinkedListNode* next;
public:
    LinkedListNode();
    LinkedListNode(Direction data);

    friend std::ostream&  operator<< (std::ostream&  out,  LinkedListNode &n);
    friend class LinkedList;
};


class LinkedList {
protected:
    void  swap(LinkedListNode* prev, LinkedListNode *l, LinkedListNode *r);

    LinkedListNode* FIRST;
    LinkedListNode* CURRENT;
    LinkedListNode* LAST;
    int count_elements;

public:
    LinkedList(); 
    ~LinkedList();


    bool insert(LinkedListNode *element);
    bool insert(LinkedListNode *element, int pos);
    bool remove();
    bool remove(int pos);

    LinkedListNode* get(int pos);
    LinkedListNode* search(LinkedListNode *element);

    bool edit(LinkedListNode* new_element, int pos);
    void sort();

    void print();

    int size();

    friend std::ostream&  operator<< (std::ostream&  out,  LinkedList& obj);
};


