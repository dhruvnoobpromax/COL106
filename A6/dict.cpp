// Do NOT add any other includes
#include "dict.h"
int maintainheight(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        int h = 1 + max(maintainheight(root->left),maintainheight(root->right));
        root->height = h;
        return h;
    }
    
}

SymNode::SymNode()
{
    key = "";
    height = -1;
    //address = -1;
    count = -1;

    par = NULL;
    left = NULL;
    right = NULL;

}

SymNode::SymNode(string k)
{
    key = k;
    height = 0;
    //address = -1;
    count = 1;

    par = NULL;
    left = NULL;
    right = NULL;

}

SymNode* SymNode::LeftLeftRotation()
{
    SymNode* y = right;
    
    if (y->left != NULL)
    {
        right = y->left;
        y->left->par = this;
        y->left = NULL;
        y->par = NULL;
    }
    else
    {
        right = NULL;
        y->par = NULL;
    }
    
    
    if (par == NULL)
    {
        par = y;
        y->left = this;
        
    }

    else if (par->left == this)
    {
        par->left = y;
        y->par = par;
        par = NULL;
    }

    else
    {
        par->right = y;
        y->par = par;
        par = NULL;
    }

    par = y;
    y->left = this;

    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    maintainheight(r);
    return r;

}

SymNode* SymNode::RightRightRotation()
{
    SymNode* x = left;

   if (x->right != NULL)
   {
        left = x->right;
        x->right->par = this;
        x->right = NULL;
        x->par = NULL;
   }
   else
    {
        left = NULL;
        x->par = NULL;
    }

   if (par == NULL)
   {
        par = x;
        x->right = this;
   }

   else if (par->right == this)
   {
        par->right = x;
        x->par = par;
        par = NULL;

   }

   else
   {
        par->left = x;
        x->par = par;
        par = NULL;
   }

   par = x;
   x->right = this;

    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    maintainheight(r);
    return r;
   
}

SymNode* SymNode::LeftRightRotation()
{
    left->LeftLeftRotation();
    RightRightRotation();
    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    return r;

}

SymNode* SymNode::RightLeftRotation()
{
    right->RightRightRotation();
    LeftLeftRotation();
    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    return r;
}

SymNode::~SymNode()
{
  
}



//Write your code below this line
int maintainheights(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        int h = 1 + max(maintainheights(root->left),maintainheights(root->right));
        root->height = h;
        return h;
    }
    
}

int balancefactor(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return ((root->right == NULL)?0:root->right->height) - ((root->left == NULL)?0:root->left->height)  ;      
    }
    
}

SymbolTable::SymbolTable()
{
    
}

void SymbolTable::insert(string k)
{
    SymNode* newnode = new SymNode(k);

    if (size == 0)
    {
        root = newnode;
        size++;
    }

    else
    {
        SymNode* head = root;
        while (head != NULL)
        {
            if (head->key > k)
            {
                if (head->left == NULL)
                {
                    head->left = newnode;
                    newnode->par = head;
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
                if(head->right == NULL)
                {
                    head->right = newnode;
                    newnode->par = head;
                    size++;
                    break;
                }
                else
                {
                    head = head->right;
                }
                
            }
            
        }
        
        maintainheights(root);
        SymNode* traversal = newnode;
        while (true)
        {
            int e = balancefactor(traversal);
            if (e == 2 or e == -2)
            {
                break;
            }
            else
            {
                if (traversal->par != NULL)
                {
                    traversal = traversal->par;
                }

                else
                {
                    traversal = traversal->par;
                    break;
                }
            }
            
        }
        

        if (traversal == NULL)
        {
            return;
        }

        SymNode* y;
        if (traversal->key > k)
        {
            y = traversal->left;
        }
        else{y = traversal->right;}

        SymNode* x;
        if (y->key > k)
        {
            x = y->left;
        }
        else{x = y->right;}

        if (traversal->left == y and y->left == x)
        {
            root = traversal->RightRightRotation();
        }
        
        else if (traversal->left == y and y->right == x)
        {
            root = traversal->LeftRightRotation();
        }

        else if (traversal->right == y and y->right == x)
        {
            root = traversal->LeftLeftRotation();
        }

        else{root = traversal->RightLeftRotation();}

        maintainheights(root);
        
        


        
        



        
        
    }
    
    

}

SymNode* SymbolTable::search(string k)
{
    SymNode* head = root;
    while (head != NULL)
    {
        if (head->key == k)
        {
            break;
        }
        
        else if (head->key < k)
        {
            head = head->right;
        }

        else{head = head->left;}

        if (head == NULL)
        {
            break;
        }
    }

    return head;
    

}

int SymbolTable::get_size()
{
    return size;

}

SymNode* SymbolTable::get_root()
{
    return root;

}

void destroy(SymNode* root)
{
    if (root != NULL)
    {
        destroy(root->left);
        destroy(root->right);
        //cout << "cleared "<< root->key <<endl;
        delete(root);
        root = NULL;
    }
    
}

SymbolTable::~SymbolTable()
{
    destroy(root);
    //free(root);
}



Dict::Dict()
{
    // Implement your function here    
}

Dict::~Dict()
{
    // Implement your function here    
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here 
 
    string word;
    vector <string> aux;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] - 'A' >= 0  and sentence[i] - 'Z' <= 0)
        {
            word += char(sentence[i] + 'a' - 'A');
        }
        else if (sentence[i] - 'a' >= 0 and sentence[i] - 'z' <= 0)            
        {word += sentence[i];}
        else
        {
            if (word != "")
            {
            aux.push_back(word);
                
            }
            
            word = "";
        }
            
            
        
    }
    if (word != "")
    {
    aux.push_back(word);
    }

    ofstream test("oop.txt",fstream::app);
    
    for (int i = 0; i < aux.size(); i++)
    {
        // if (aux[i] == "council")
        // {
        //     for (int i = 0; i < aux.size(); i++)
        //     {
        //         test << aux[i] << " ";
        //     }
        //     test << endl;
            
        // }

        
        SymNode* ss = avl.search(aux[i]);
        if (ss == nullptr)
        {
            avl.insert(aux[i]);
            
        }

        else
        {
            
            ss->count += 1;
        }
    }
    
    
    return;
}

int Dict::get_word_count(string word){
    SymNode* ss = avl.search(word);
    if (ss == nullptr)
    {
        return 0;
    }

    else
    {
        return ss->count;
    }
    
     
    return -1;
}

vector <string> a;

void ino(SymNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    ino(root->left);

    a.push_back(root->key + " : " + std::to_string(root->count));

    ino(root->right);    
}


void Dict::dump_dictionary(string filename)
{
    ofstream dest(filename + ".txt",fstream::app);
    ino(avl.root);

    for (int i = 0; i < a.size(); i++)
    {
        dest << a[i] << "\n";
    }

    a.clear();
    
    return;
}


// int main()
// {
//     string w = "damn nigga how ya doin ya ya";

//     Dict b;

//     b.insert_sentence(0,0,0,0,w);
//     b.dump_dictionary("out");

//     cout << "dd";
// }
