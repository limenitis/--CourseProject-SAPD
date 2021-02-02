#pragma once
#include <iostream>
#include <fstream>

LinkedListNode* gen_rand_LinkedListNode();
char            gen_rand_key(bool);

class LinkedListNode
{
public:
    // Data data;
    LinkedListNode* next;
    LinkedListNode* prev;
};

class LinkedList {
protected:
    void  swap(LinkedListNode *l, LinkedListNode *r);

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

    LinkedListNode  get(int pos);
    LinkedListNode* search(LinkedListNode element);

    bool edit(LinkedListNode new_element, int pos);
    void bubble_sort();

    void read();
    void read(char str[]);
    void save();
    void save(char str[]);
    void print();

    int size();

    friend std::ostream&  operator<< (std::ostream&  out,  LinkedList& obj);

    friend std::ofstream& operator<< (std::ofstream& fout, LinkedList& obj);
    friend std::ifstream& operator>> (std::ifstream& fin,  LinkedList& obj);
};


std::ostream&  operator<< (std::ostream&  out,  LinkedListNode &n);

