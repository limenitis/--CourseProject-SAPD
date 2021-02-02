#pragma once
#include ".\..\include\LinkedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

LinkedList::LinkedList()
{
    FIRST = nullptr;
    CURRENT = nullptr;
    LAST = nullptr;
    count_elements = 0;
}

LinkedList::~LinkedList()
{
    if (count_elements != 0)
    {
        while (count_elements != 0 && FIRST->next != nullptr)
        {
            CURRENT = FIRST;
            FIRST = FIRST->next;
            delete CURRENT;
            count_elements -= 1;
        }
        if (count_elements != 0)
        {
            delete FIRST;
        }
    }
}

bool LinkedList::insert(LinkedListNode *new_element, int pos)
{
    if (pos > count_elements)
    {
        pos = count_elements;
        cout << "[Linked list] [insert] : pos over count elements \n";
        cout << "[Linked list] [insert] : insert last element in list \n";
    }
    else if(pos < 0)
    {
        pos = 0;
        cout << "[Linked list] [insert] : pos less 0 \n";
        cout << "[Linked list] [insert] : insert first element in list \n";
    }

    if(FIRST == nullptr)
    {
        FIRST = new_element;
        LAST = new_element;
        new_element->next = nullptr;
        new_element->prev = nullptr;
    }
    else
    {
        if (pos == 0) 
        {
            new_element->prev = nullptr;
            FIRST->prev = new_element;
            new_element->next = FIRST;

            FIRST = new_element;
        }
        else if (pos == count_elements)
        {
            new_element->next = nullptr;
            LAST->next = new_element;
            new_element->prev = LAST;

            LAST = new_element;
        }
        else
        {
            CURRENT = FIRST;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }

            //          paste before CURRENT
            CURRENT->prev->next = new_element;
            new_element->prev = CURRENT->prev;
            CURRENT->prev = new_element;
            new_element->next = CURRENT;
        }
    }

    count_elements += 1;
    return true;
}

bool LinkedList::remove(int pos)
{
    if (pos > count_elements - 1 && count_elements != 0)
    {
        pos = count_elements - 1;
        cout << "[Linked list] [remove] : pos over count elements \n";
        cout << "[Linked list] [remove] : delete last element in list \n";
    }
    else if(pos < 0)
    {
        pos = 0;
        cout << "[Linked list] [remove] : pos less 0 \n";
        cout << "[Linked list] [remove] : command were ignored \n";
        return false;
    }

    if(FIRST == nullptr || count_elements == 0)
    {
        // list empty
        cout << "[Linked list] [remove] : list empty \n";
        return false;
    }
    else if(FIRST == LAST)
    {
        // only 1 element
        delete FIRST;
    }
    else
    {
        if (pos == 0) 
        {
            FIRST = FIRST->next;
            delete FIRST->prev;
            FIRST->prev = nullptr;
        }
        else if (pos == count_elements - 1)
        {
            LAST = LAST->prev;
            delete LAST->next;
            LAST->next = nullptr;
        }
        else
        {
            CURRENT = FIRST;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }

            //          paste before CURRENT        // it's ok
            CURRENT->prev->next = CURRENT->next;    // becose first and last 
            CURRENT->next->prev = CURRENT->prev;    // processing apart
            delete CURRENT;
        }
    }
    
    count_elements -= 1;
    return true;
}

LinkedListNode LinkedList::get(int pos)
{
    if (pos == -1)
    {
        pos = count_elements - 1;
    }
    else if (pos > count_elements - 1 && count_elements != 0)
    {
        pos = count_elements - 1;
        cout << "[Linked list] [get] : pos over count elements \n";
        cout << "[Linked list] [get] : return last element in list \n";
    }
    else if(pos < -1)
    {
        pos = 0;
        cout << "[Linked list] [get] : pos less 0 \n";
        cout << "[Linked list] [get] : return first element in list \n";
    }


    if(FIRST == nullptr || count_elements == 0)
    {
        // list empty
        cout << "[Linked list] [get] : list empty \n";
        // LinkedListNode error_LinkedListNode;
        // error_LinkedListNode.destination[0] = '\0';
        // error_LinkedListNode.number = 0;
        // error_LinkedListNode.time.str[0] =  {'\0'};
        // return error_LinkedListNode;
    }
    else if(FIRST == LAST)
    {
        // only 1 element
        return *FIRST;
    }
    else
    {
        if (pos == 0) 
        {
            return *FIRST;
        }
        else if (pos == count_elements - 1)
        {
            return *LAST;
        }
        else
        {
            CURRENT = FIRST;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }
            return *CURRENT;
        }
    }
}

LinkedListNode *LinkedList::search(LinkedListNode element)
{
    // find LinkedListNode for nuber
    // CURRENT = FIRST;
    // if(CURRENT == nullptr || count_elements == 0) { return nullptr; }

    // while (CURRENT->next != nullptr)
    // {
    //     if (CURRENT->number == number)
    //     {
    //         return CURRENT;
    //     }
    //     CURRENT = CURRENT->next;
    // }

    // if(CURRENT->number == number){ return CURRENT; }
    // else { return nullptr; }
}

bool LinkedList::edit(LinkedListNode new_element, int pos)
{
    LinkedListNode *element;
    element = search(new_element);

    if (element == nullptr) 
    {
        cout << "[LinkedList::edit] : element not found \n";
        return false;
    }

    // element->number = new_element.number;
    // element->time = new_element.time;
    // int i = 0;
    // for(auto e : element->destination)
    // {
    //     element->destination[i] = new_element.destination[i];
    //     i++;
    // }
}

void LinkedList::swap(LinkedListNode *l, LinkedListNode *r)
{
    LinkedListNode *nex = r->next;
    LinkedListNode *last = l->prev;

    if (l == FIRST)
    {
        if (last != nullptr) { last->next = r; }
        l->next = nex;
        l->prev = r;
        r->next = l;
        r->prev = last;
        if (nex != nullptr) { nex->prev = l; }
        FIRST = r;
    }
    else if(r == LAST)
    {
        if (last != nullptr) { last->next = r; }
        l->next = nex;
        l->prev = r;
        r->next = l;
        r->prev = last;
        if (nex != nullptr) { nex->prev = l; }
        LAST = l;
    }
    else
    {
        if (last != nullptr) { last->next = r; }
        l->next = nex;
        l->prev = r;
        r->next = l;
        r->prev = last;
        if (nex != nullptr) { nex->prev = l; }
    }
}

void LinkedList::bubble_sort()
{
    bool swaps = 1;
    while (swaps){
        swaps = false;
        for (LinkedListNode *ptr = FIRST; ptr != nullptr && ptr->next != nullptr; ptr = ptr->next) {
            // if ( ptr->number > ptr->next->number )
            {
                swap(ptr, ptr->next);
                swaps = true;
            }
        }
    }
}

void LinkedList::read()
{
    ifstream fin("in.txt");   // входной поток
    fin >> *this;
    fin.close();
}

void LinkedList::read(char str[])
{
    ifstream fin(str);   // входной поток
    fin >> *this;
    fin.close();
}

void LinkedList::save()
{
    ofstream fout("out.txt");  // выходной поток
    fout << *this;
    fout.close();
}

void LinkedList::save(char str[])
{
    ofstream fout(str);  // выходной поток
    fout << *this;
    fout.close();
}


void LinkedList::print()
{
    CURRENT = FIRST;
    int num = count_elements;
    cout << "\n";
    cout << "+------+----------+---------------------------+----------+ \n";
    cout << "|  id  |  number  |        destination        |   time   | \n";
    while (CURRENT != nullptr && num != 0)
    {
        cout << "|------|----------|---------------------------|----------| \n";
        cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(5)  << count_elements - num;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(9)  << CURRENT->number;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(26) << CURRENT->destination;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(9)  << CURRENT->time;
                                   cout << "|\n" /* ╏ ╎ ║ ╽ */   ;
        CURRENT = CURRENT->next;
        num--;
    }
    cout << "+------+----------+---------------------------+----------+ \n";
    cout << "\n";
}

int LinkedList::size() { return count_elements; }

std::ostream  &operator<<(std::ostream &out,   LinkedList &obj)
{
    out << "\n";
    obj.print();
    out << "\n";

    return out;
}

std::ofstream &operator<<(std::ofstream &fout, LinkedList &obj)
{
    obj.CURRENT = obj.FIRST;
    int num = obj.count_elements;
    while (obj.CURRENT != nullptr && num > 0)
    {
        // fout << obj.CURRENT->number << endl;
        // fout << obj.CURRENT->destination << endl;
        // fout << obj.CURRENT->time << endl;
        obj.CURRENT = obj.CURRENT->next;
        num--;
    }
    fout << "\n";

    return fout;
}

std::ifstream &operator>>(std::ifstream &fin,  LinkedList &obj)
{
    while (!fin.eof())
    {
        LinkedListNode* new_element = new LinkedListNode;
        // fin >> new_element->number;
        // fin >> new_element->destination;
        // fin >> new_element->time;
        obj.insert(new_element);
    }
    obj.remove();

    return fin;
}

std::ostream  &operator<<(std::ostream  &out,  LinkedListNode &n)
{
    out << "+----------+---------------------------+----------+ \n";
    out << "|  number  |        destination        |   time   | \n";
    out << "+----------+---------------------------+----------+ \n";
    // out.setf(std::ios::left); out << "| " << std::setw(9)  << n.number;
    // out.setf(std::ios::left); out << "| " << std::setw(26) << n.destination;
    // out.setf(std::ios::left); out << "| " << std::setw(9)  << n.time;
    out << "|\n";
    out << "+----------+---------------------------+----------+ \n";

    return out;
}

