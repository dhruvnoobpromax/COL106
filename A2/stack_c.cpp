#include <iostream>
#include "stack_c.h"
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;


void PrintfromTop(List* k)
{
    if(k->get_size() == 0){return;}
    else
    {
        int a = k->delete_tail();
        cout << a << endl;
        PrintfromTop(k);
        k->insert(a);

    }
}

    // Constructor
Stack_C::Stack_C()
{
    List* n = new (std::nothrow) List();
    if(n == nullptr){throw std::runtime_error("Out of Memory");}
    stk = n;
}

    // Destructor
Stack_C::~Stack_C()
{
    delete stk;
    stk = nullptr;
}

    void Stack_C::push(int data)
    {
        stk->insert(data);
    }

    int Stack_C::pop()
    {
        if(stk->get_size() == 0){throw std::runtime_error("Empty Stack");}
        else {return stk->delete_tail(); } }

    int Stack_C::get_element_from_top(int idx)
    {
        if(idx > stk->get_size() - 1){throw std::runtime_error("Index out of range");}
        else
        {
            Node* temp = stk->get_head();
            for(int i = 0; i < stk->get_size() -idx; i++)
            {
                temp = temp->next;
            }
            return temp->get_value();
        }
    }

    int Stack_C::get_element_from_bottom(int idx)
    {
        if(idx > stk->get_size() - 1){throw std::runtime_error("Index out of range");}
        else
        {
            Node* temp = stk->get_head();
            for(int i = 0; i<idx; i++)
            {
                temp = temp->next;
            }
            return temp->next->get_value();
        }
    }

    void Stack_C::print_stack(bool top_or_bottom)
    {
        if(!top_or_bottom)
        {
            Node* temp = stk->get_head();
            for(int i = 0; i < stk->get_size(); i++)
            {
                cout << temp->get_value() << endl;
                temp = temp->next;
            }
        }
        else
        {
            PrintfromTop(stk); 
        }
    }

    int Stack_C::add(){
        if(stk->get_size() <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk->delete_tail();
            int b = stk->delete_tail();
            int c = a+b;
            stk->insert(c);
            return c;

        }}

    int Stack_C::subtract(){
        if(stk->get_size() <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk->delete_tail();
            int b = stk->delete_tail();
            int c = b-a;
            stk->insert(c);
            return c;

        }}

    int Stack_C::divide(){if(stk->get_size() <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
        if(stk->get_size() <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk->delete_tail();
            int b = stk->delete_tail();
            if(a == 0){throw std::runtime_error("Divide by Zero Error");}
            else
            {
            int c = b/a;
            if(a < 0 ^ b < 0)
            {
                double e = double(b)/double(a);
                double f = b/a;
                if(double(f) != e){c -= 1;}
                
                
            }
            stk->insert(c);
            return c;}

        }

        }}

    int Stack_C::multiply()
    {
        if(stk->get_size() <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk->delete_tail();
            int b = stk->delete_tail();
            int c = a*b;
            stk->insert(c);

            return c;

        }
    }

    List* Stack_C::get_stack(){return stk;} // Get a pointer to the linked list representing the stack

    int Stack_C::get_size(){return stk->get_size();} // Get the size of the stack

