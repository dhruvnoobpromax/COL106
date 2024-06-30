#include <iostream>
#include "stack_a.h"
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;




Stack_A::Stack_A()
{
   size = 0;

}
    void Stack_A::push(int data)
    {
        if(size < 1024)
        {
            stk[size] = data;
            size++;
        }
        else
        {
            throw std::runtime_error("Stack Full");
        }
    }

    int Stack_A::pop()
    {
        if(size == 0){throw std::runtime_error("Empty Stack");}
        else{
        int a = Stack_A::stk[size-1];
        size--;
        return a;
        }
    }

    int Stack_A::get_element_from_top(int idx)
    {
        if(idx > size - 1){throw std::runtime_error("Index out of range");}
        else{return Stack_A::stk[size-1-idx];}
    }

    int Stack_A::get_element_from_bottom(int idx)
    {   
        if(idx > size-1){throw std::runtime_error("Index out of range");}
        else{return Stack_A::stk[idx];}
    }

    void Stack_A::print_stack(bool top_or_bottom)
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

    int Stack_A::add()
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

    int Stack_A::subtract(){
        if(size <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk[size-1];
            int b = stk[size-2];
            int c = b-a;
            stk[size-2] = c;
            size--;
            return c;

        }}

    int Stack_A::multiply(){
        if(size <2){throw std::runtime_error("Not Enough Arguments");}
        else
        {
            int a = stk[size-1];
            int b = stk[size-2];
            int c = a*b;
            stk[size-2] = c;
            size--;
            return c;

        }}

    int Stack_A::divide()
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
            if(a < 0 ^ b < 0)
            {
                double e = double(b)/double(a);
                double f = b/a;
                if(double(f) != e){c -= 1;}
                
                
            }
            stk[size-2] = c;
            size--;

            return c;}

        }}

    int* Stack_A::get_stack(){return stk;}

    int Stack_A::get_size(){return Stack_A::size;}

