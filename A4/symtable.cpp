/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
#include <iostream>

SymbolTable::SymbolTable()
{
    size = 0;
    root = new SymEntry();
    //cout << "root created at " << this <<endl;
}

SymbolTable::~SymbolTable()
{
    root->~SymEntry();
    //cout << "root deleted at " << this << endl; 
}

    // Insert a key value pair in the symbol table

void SymbolTable::insert(string k, UnlimitedRational* v)
{
    if (size == 0)
    {
        root->key = k;
        root->val = v;
        size++;
    }
    else
    {
        SymEntry* head = root;
        SymEntry* newnode = new SymEntry(k,v);
        while (head!= nullptr)
        {
            if (head->key > k)
            {
                if (head->left == nullptr)
                {
                    head->left = newnode;
                    size++;
                    break;
                }

                else
                {
                    head = head->left;
                }

            
            }

            else
            {
                if (head->right == nullptr)
                {
                    head->right = newnode;
                    size++;
                    break;
                }
                
                else
                {
                    head = head->right;
                }
            }
            
        }
        
          
        
    }
    
}
    // Remove a key (and value) in the symbol table


void SymbolTable::remove(string k)
{
    SymEntry* head = root;
    SymEntry* parent = nullptr;
    while (head!= nullptr)
    {
        if (head->key < k)
        {
            parent = head;
            head = head->right;
            

        }

        else if (head->key > k)
        {
            
            parent = head;
            head = head->left;
            
        }

        else if (head->key == k)
        {
            //return head->val;
            break;
        }
    }

    if (head == nullptr)
    {
        return;
    }
    

    if (head->left == nullptr and head->right == nullptr)
    {
        head->~SymEntry();
        head = nullptr;
        size --;
    }
    
    if (head->left == nullptr and head->right != nullptr)
    {
        SymEntry* temp = head;
        parent->right = head->right;
        temp->right = nullptr;

        temp->~SymEntry();
        size--;
        return;
    }

    if (head->left != nullptr and head->right == nullptr)
    {
        SymEntry* temp = head;
        parent->left = head->left;
        temp->left = nullptr;
        temp->~SymEntry();
        size--;
        return;
    }

    if (head->left != nullptr and head->right != nullptr)
    {

        SymEntry* succp = head;
        SymEntry* succ = head->right;

        while (succ->left != nullptr)
        {
            succp = succ;
            succ = succ->left;
        }

        if (succp != head)
        {
            succp->left = succ->right;
        }

        else{succp->right = succ->right;}

        head->key = succ->key;
        head->val = succ->val;

        delete succ;
        
        

    }

    
    


        
    
    
    
    
    

}
 
// Find the val corresponding to the key in the symbol table
UnlimitedRational* SymbolTable::search(string k)
{
    SymEntry* head = root;
    while (head!= nullptr)
    {
        if (head->key < k)
        {
            head = head->right;
        }

        else if (head->key > k)
        {
            head = head->left;
        }

        else if (head->key == k)
        {
            return head->val;
            break;
        }
    }
    return nullptr;
}

    // Get size
int SymbolTable::get_size(){return size;}

    // Get root 
SymEntry* SymbolTable::get_root(){return root;}
int main()
{
    SymbolTable a;
    UnlimitedInt x(8);
    UnlimitedInt y(9);

    UnlimitedRational d(&x,&y);

    a.insert("g",&d);
    a.insert("h",&d);
    a.insert("f",&d);
    a.insert("i",&d);
    //a.insert("h",&d);
    a.remove("h");
    std::cout << a.get_size();



}