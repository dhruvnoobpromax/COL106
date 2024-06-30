#include <iostream>
#include "list.h"
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;


List::List()
{
    size = 0;
    Node* x = new (std::nothrow) Node(1);
    if(x == nullptr){throw std::runtime_error("Out of Memory");}
    Node* y = new (std::nothrow) Node(1);
    if(y == nullptr){throw std::runtime_error("Out of Memory");}

    sentinel_head = x;
    sentinel_tail = y;
    sentinel_head->prev = nullptr;
    sentinel_tail->next = nullptr;
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;

}

    // Insert an element at the tail of the linked list 
void List::insert(int v)
{
    Node* n = new (std::nothrow) Node(v,nullptr,nullptr);
    if(n == nullptr){throw std::runtime_error("Out of Memory");}
    Node* temp = sentinel_tail->prev;
    sentinel_tail->prev->next = n;
    n->prev = temp;
    n->next = sentinel_tail;
    sentinel_tail->prev = n;

    size ++;
}

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
int List::delete_tail()
{
    int a = sentinel_tail->prev->get_value();
    Node* temp = sentinel_tail->prev;
    sentinel_tail->prev->prev->next = sentinel_tail;
    sentinel_tail->prev = sentinel_tail->prev->prev;

    delete temp;
    size --;

    return a;
    
}

List::~List()
{
    for(int i=size; i>0; i--)
    {
        delete_tail();
    }

    sentinel_head->next = nullptr;
    sentinel_tail->prev = nullptr;
    delete sentinel_head;
    delete sentinel_tail;

}

    // Return the size of the linked list 
    // Do not count the sentinel elements
int List::get_size(){return size;}

    // Return a pointer to the sentinel head of the linked list 
Node* List::get_head(){return sentinel_head;}

