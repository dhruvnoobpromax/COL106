#include <iostream>
#include "stack_b.h"
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;

Stack_B::Stack_B() 
{
    size = 0;
    capacity = 1024;

    stk = new (std::nothrow) int[capacity];
    if(stk == nullptr){throw std::runtime_error("Out of Memory");} 
}

Stack_B::~Stack_B()
{
    delete [] stk;
    // stk = nullptr;
    
}

void Stack_B::push (int data)
{
    if(size ==capacity)
    {
        capacity = capacity*2;
        int* newstk = new (std::nothrow) int[capacity];
        if(stk == nullptr){throw std::runtime_error("Out of Memory");}
        for (int i = 0; i < size; i++)
        {
            newstk[i] = stk[i];
        }
        //delete [] stk;
        stk = newstk;

        stk[size] = data;
        size++;
    }
    else
    {
        stk[size] = data;
        size++;
    }
}

int Stack_B::pop()
{
    if(size <= capacity/4 and size > 0)
    {
        capacity = capacity/2;
        int* newstk = new (std::nothrow) int[capacity];
        if(stk == nullptr){throw std::runtime_error("Out of Memory");}
        for (int i = 0; i < size; i++)
        {
            newstk[i] = stk[i];
        }

        stk = newstk;

        int a = Stack_B::stk[size-1];
        size--;
        return a;
    }
    else
    {
        if(size == 0){throw std::runtime_error("Empty Stack");}
        else{
        int a = Stack_B::stk[size-1];
        size--;
        return a;
        }
    }
}

int Stack_B::get_element_from_top(int idx)
    {
        if(idx > size - 1){throw std::runtime_error("Index out of range");}
        else{return Stack_B::stk[size-1-idx];}
    }

int Stack_B::get_element_from_bottom(int idx)
    {   
        if(idx > size-1){throw std::runtime_error("Index out of range");}
        else{return Stack_B::stk[idx];}
    }

void Stack_B::print_stack(bool top_or_bottom)
    {
        if(top_or_bottom == 0)
        {
            for(int i = 0; i < size; i++)
            {cout << stk[i]<<endl;}
        }
        if(top_or_bottom == 1)
        {
            for(int i = size-1; i>=0; i--)
            {cout << stk[i]<<endl;}
        }
    }

int Stack_B::add()
    {
        if(size <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk[size-1];
            int b = stk[size-2];
            int c = a+b;
            stk[size-2] = c;
            size--;
            return c;

        }
    }

int Stack_B::subtract()
    {
    if(size <2){throw std::runtime_error("Not Enough Arguments");}
    else
    {
        int a = stk[size-1];
        int b = stk[size-2];
        int c = b-a;
        stk[size-2] = c;
        size--;
        return c;
    }
    }

int Stack_B::multiply(){
    if(size <2){throw std::runtime_error("Not Enough Arguments");}
    else
    {
        int a = stk[size-1];
        int b = stk[size-2];
        int c = a*b;
        stk[size-2] = c;
        size--;
        return c;

    }
    }

int Stack_B::divide()
{
    if(size <2){throw std::runtime_error("Not Enough Arguments");}
    else
    {
        int a = stk[size-1];
        int b = stk[size-2];
        if(a == 0)
        {   size -= 2;
            throw std::runtime_error("Divide by Zero Error");
        }
            
        else
        {
        int c = b/a;
        if(a*b < 0)
        {
            double e = double(b)/double(a);
            double f = b/a;
            if(double(f) != e){c -= 1;}
        }
        stk[size-2] = c;
        size--;

        return c;
        }
    }
}

int* Stack_B::get_stack(){return stk;}

int Stack_B::get_size(){return size;}
