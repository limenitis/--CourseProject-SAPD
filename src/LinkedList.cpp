#pragma once
#include ".\..\include\LinkedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;

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

bool LinkedList::insert(LinkedListNode *element)
{
    insert(element, count_elements);
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
    }
    else
    {
        if (pos == 0) 
        {
            new_element->next = FIRST;
            FIRST = new_element;
        }
        else if (pos == count_elements)
        {
            new_element->next = nullptr;
            LAST->next = new_element;
            LAST = new_element;
        }
        else // paste before CURRENT
        {

            CURRENT = FIRST;
            pos--;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }

            new_element->next = CURRENT->next;
            CURRENT->next = new_element;
        }
    }

    count_elements += 1;
    return true;
}

bool LinkedList::remove()
{
    remove(count_elements);
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
            void *tmp = FIRST;
            FIRST = FIRST->next;
            delete tmp;
        }
        // else if (pos == count_elements - 1)
        // {
        //     void *tmp = LAST;
        //     FIRST = FIRST->next;
        //     delete tmp;
        // }
        else
        {
            CURRENT = FIRST;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }

            void *tmp = CURRENT;
            CURRENT = CURRENT->next;
            delete tmp;
        }
    }
    
    count_elements -= 1;
    return true;
}

LinkedListNode* LinkedList::get(int pos)
{
    if (pos > count_elements - 1 && count_elements != 0)
    {
        pos = count_elements - 1;
        cout << "[Linked list] [get] : pos over count elements \n";
        cout << "[Linked list] [get] : return last element in list \n";
    }
    else if(pos < 0)
    {
        pos = 0;
        cout << "[Linked list] [get] : pos less 0 \n";
        cout << "[Linked list] [get] : return first element in list \n";
    }


    if(FIRST == nullptr || count_elements == 0)
    {
        // list empty
        cout << "[Linked list] [get] : list empty \n";
    }
    else if(FIRST == LAST)
    {
        // only 1 element
        return FIRST;
    }
    else
    {
        if (pos == 0) 
        {
            return FIRST;
        }
        else if (pos == count_elements - 1)
        {
            return LAST;
        }
        else
        {
            CURRENT = FIRST;
            while (CURRENT->next != nullptr && pos > 0)
            {
                CURRENT = CURRENT->next;
                pos -= 1;
            }
            return CURRENT;
        }
    }
}

LinkedListNode *LinkedList::search(LinkedListNode* element)
{
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



    return nullptr; // cork
}

bool LinkedList::edit(LinkedListNode *new_element, int pos)
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

void LinkedList::swap(LinkedListNode* prev, LinkedListNode *l, LinkedListNode *r)
{
    if (l == FIRST)
    {
        l->next = r->next;
        r->next = l;
        prev->next = r;
        FIRST = r;
    }
    else if(r == LAST)
    {
        l->next = r->next;
        r->next = l;
        prev->next = r;
        LAST = l;
    }
    else
    {
        l->next = r->next;
        r->next = l;
        prev->next = r;
    }

    // LinkedListNode *nex = r->next;
    // LinkedListNode *last = l->prev;
    // if (l == FIRST)
    // {
    //     if (last != nullptr) { last->next = r; }
    //     l->next = nex;
    //     l->prev = r;
    //     r->next = l;
    //     r->prev = last;
    //     if (nex != nullptr) { nex->prev = l; }
    //     FIRST = r;
    // }
    // else if(r == LAST)
    // {
    //     if (last != nullptr) { last->next = r; }
    //     l->next = nex;
    //     l->prev = r;
    //     r->next = l;
    //     r->prev = last;
    //     if (nex != nullptr) { nex->prev = l; }
    //     LAST = l;
    // }
    // else
    // {
    //     if (last != nullptr) { last->next = r; }
    //     l->next = nex;
    //     l->prev = r;
    //     r->next = l;
    //     r->prev = last;
    //     if (nex != nullptr) { nex->prev = l; }
    // }
}

void LinkedList::sort()
{



    // bool swaps = 1;
    // while (swaps){
    //     swaps = false;
    //     for (LinkedListNode *ptr = FIRST; ptr != nullptr && ptr->next != nullptr; ptr = ptr->next) {
    //         // if ( ptr->number > ptr->next->number )
    //         {
    //             swap(ptr, ptr->next);
    //             swaps = true;
    //         }
    //     }
    // }
}

void LinkedList::print()
{
    CURRENT = FIRST;
    int num = count_elements;
    cout << "\n";
    // cout << "+------+----------+---------------------------+----------+ \n";
    // cout << "|  id  |  number  |        destination        |   time   | \n";
    while (CURRENT != nullptr && num != 0)
    {
        // cout << "|------|----------|---------------------------|----------| \n";
        cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(5)  << count_elements - num;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(9)  << CURRENT->number;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(26) << CURRENT->destination;
        // cout.setf(std::ios::left); cout << "| "  /* ╏ ╎ ║ ╽ */ << std::setw(9)  << CURRENT->time;
                                   cout << "|\n" /* ╏ ╎ ║ ╽ */   ;
        CURRENT = CURRENT->next;
        num--;
    }
    // cout << "+------+----------+---------------------------+----------+ \n";
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

std::ostream  &operator<<(std::ostream  &out,  LinkedListNode &n)
{
    // out << "+----------+---------------------------+----------+ \n";
    // out << "|  number  |        destination        |   time   | \n";
    // out << "+----------+---------------------------+----------+ \n";
    // out.setf(std::ios::left); out << "| " << std::setw(9)  << n.number;
    // out.setf(std::ios::left); out << "| " << std::setw(26) << n.destination;
    // out.setf(std::ios::left); out << "| " << std::setw(9)  << n.time;
    // out << "|\n";
    // out << "+----------+---------------------------+----------+ \n";

    return out;
}

