//
//  symbol_table.cpp
//  
//
//  Created by Abraham Ayorinde on 9/7/22.
//


#include "symbol_table.h"
#include <iostream>

using namespace std;
// Function to modify an identifier
bool SymbolTable::modify(string id, string s,
                         string t, int l)
{
    int index = hashf(id);
    SymbolNode* start = head[index];
  
    if (start == NULL)
        return "-1";
  
    while (start != NULL)
    {
        if (start->identifier == id)
        {
            start->scope = s;
            start->type = t;
            start->lineNo = l;
            return true;
        }
        start = start->next;
    }
  
    return false; // id not found
}
  
// Function to delete an identifier
bool SymbolTable::deleteRecord(string id)
{
    int index = hashf(id);
    SymbolNode* tmp = head[index];
    SymbolNode* par = head[index];
  
    // no identifier is present at that index
    if (tmp == NULL) {
        return false;
    }
    // only one identifier is present
    if (tmp->identifier == id && tmp->next == NULL) {
        tmp->next = NULL;
        delete tmp;
        return true;
    }
  
    while (tmp->identifier != id && tmp->next != NULL) {
        par = tmp;
        tmp = tmp->next;
    }
    if (tmp->identifier == id && tmp->next != NULL) {
        par->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
  
    // delete at the end
    else {
        par->next = NULL;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    return false;
}
  
// Function to find an identifier
int SymbolTable::find(string id)
{
    int index = hashf(id);
    SymbolNode* start = head[index];
  
    if (start == NULL)
        return -1;
  
    while (start != NULL) {
  
        if (start->identifier == id)
        {
            //start->print();//
            return 0;
            //return start->scope;
        }
  
        start = start->next;
    }
  
    return -1; // not found
}
  
// Function to insert an identifier
bool SymbolTable::insert(string id, string scope,
                         string Type, int lineno)
{
    int index = hashf(id);
    SymbolNode* p = new SymbolNode(id, scope, Type, lineno);
  
    if (head[index] == NULL)
    {
        head[index] = p;
        cout << "\n"<<"Head created: "<<id << " inserted"<<endl;
  
        return true;
    }
  
    else
    {
        SymbolNode* start = head[index];
        while (start->next != NULL)
        {
            start = start->next;
        }
        start->next = p;
        cout << "\n"<<"Child inserted: "<< id << " inserted"<<endl;
  
        return true;
    }
  
    return false;
}
  
int SymbolTable::hashf(string id)
{
    int asciiSum = 0;
  
    for (int i = 0; i < id.length(); i++)
    {
        asciiSum = asciiSum + id[i];
    }
  
    return (asciiSum % MAX);
}
