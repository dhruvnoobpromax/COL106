#include <iostream>
#include "node.h"
#include <stdexcept>


using namespace std;


Node::Node(bool sentinel){is_sentinel = sentinel;}   

    // Use to construct a regular node
Node::Node(int v, Node* nxt, Node* prv)
{
    value = v;
    next = nxt;
    prev = prv;
}

    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
bool Node::is_sentinel_node()
{
    if(is_sentinel == true){return true;}
    else{return false;}
}

    // Return the value of a node
int Node::get_value(){return value;}

