/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"
#include <iostream>

Evaluator::Evaluator()
{
    expr_trees = vector<ExprTreeNode* >();
    symtable = new SymbolTable;
}

Evaluator::~Evaluator()
{
    delete symtable;
}

    // Read an input vector of tokens (strings)
    // Parse it and convert it to a parse tree
    // Push the root of the tree in the expr_trees

int indexofsign(vector<string> code,int initial, int final)
{

    int i = initial;
    int noofopen = 0;
    while (code[i] == "(")
    {
        i++;
        noofopen++;
    }

    int index = i;
    if (noofopen != 0)
    {
        for (int j = i; j < final-1; j++)
        {
            if (noofopen == 1)
            {
                break;
            }
        
            else if (code[j] == ")")
            {
                noofopen--;
            }

            index++;
        }
    }

    for (int j = index; j < final; j++)
    {
        if (code[j] == "+" or code[j] ==  "-" or code[j] ==  "*" or code [j] == "/")
            {
                return j;
            }
    }

    return -1;
    

    
    
    
    
    


}

ExprTreeNode* build_tree(vector<string> code, int initial, int final)
{
    UnlimitedInt a("0");
    int k = indexofsign(code, initial , final);
    
    if (k == -1)
    {
        ExprTreeNode* root = new ExprTreeNode(code[initial],&a);
        return root;
    }
    ExprTreeNode* root = new ExprTreeNode(code[k],&a);
    

    root->left = build_tree(code, initial+1,k-1);
    root->right = build_tree(code,k+1,final-1);

    return root;


}


void Evaluator::parse(vector<string> code)
{
    UnlimitedInt a(0);
    ExprTreeNode* root = new ExprTreeNode(":=",&a);
    ExprTreeNode* var = new ExprTreeNode(code[0],&a);
    root->left = var;

    root->right = build_tree(code,2,code.size()-1);

    expr_trees.push_back(root);
    
}

UnlimitedRational* solve(ExprTreeNode* exprtree, SymbolTable* symtable)
{
    if (exprtree->type == "ADD")
    {
        UnlimitedRational* a =  UnlimitedRational::add(solve(exprtree->left,symtable),solve(exprtree->right,symtable));
        exprtree->evaluated_value = a;
        return a;
    }

    else if (exprtree->type == "SUB")
    {
        UnlimitedRational* a = UnlimitedRational::sub(solve(exprtree->left,symtable),solve(exprtree->right,symtable));
        exprtree->evaluated_value = a;
        return a;
    }

    else if (exprtree->type == "MUL")
    {
        UnlimitedRational* a =  UnlimitedRational::mul(solve(exprtree->left,symtable),solve(exprtree->right,symtable));
        exprtree->evaluated_value = a;
        return a;
    }

    else if (exprtree->type == "DIV")
    {
        UnlimitedRational* a = UnlimitedRational::div(solve(exprtree->left,symtable),solve(exprtree->right,symtable));
        exprtree->evaluated_value = a;
        return a;
    }
    
    else if (exprtree->type == "VAL")
    {
        return exprtree->evaluated_value;
    }

    else if (exprtree->type == "VAR")
    {
        UnlimitedRational* a = symtable->search(exprtree->id);
        exprtree->evaluated_value = a;
        return a;
    }  

    return nullptr;
}

    // Evaluate the last element of the expr_trees
    // This function is guaranteed to be called immediately 
    // after a call to parse, and will be only called ONCE
    // for a tree
    // Also populate the symbol tables
void Evaluator::eval()
{
    ExprTreeNode* root = expr_trees[expr_trees.size()-1];

    string s = root->id;

    UnlimitedRational* a = solve(root->right,symtable);

    symtable->insert(s,a);
}

int main()
//v:=(13+(2/51))
{
    vector<string> code = {"v", ":=" , "(","13","+","(","2","/","51",")",")"};
    vector<string> code1 = {"v" , ":=", "(","2","+","3",")"};
    Evaluator a;

    a.parse(code);
    a.eval();
    cout << "done";
}