/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"
#include <iostream>

SymEntry::SymEntry()
{
    key = "";
    val = nullptr;
    left = nullptr;
    right = nullptr;
    //cout << "entry created at " << this;
}

SymEntry::SymEntry(string k, UnlimitedRational* v)
{
    key = k;
    val = v;
    left = nullptr;
    right = nullptr;
    //cout << "entry created at " << this;
}

SymEntry::~SymEntry()
{
    //cout << "deti" << endl;
    val->~UnlimitedRational();
   // val = nullptr;
    //cout << "detc at " << this << endl;

}
