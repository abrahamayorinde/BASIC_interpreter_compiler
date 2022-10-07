//
//  symbol_node.h
//  
//
//  Created by Abraham Ayorinde on 9/9/22.
//

#ifndef symbol_node_h
#define symbol_node_h

using namespace std;

#include <string>
//
//  Node.h
//
//
//  Created by Abraham Ayorinde on 9/7/22.
//


struct SymbolNode{
public:
    string identifier, scope, type;
    int lineNo;
    string name;
    int size, dimension, declaration, usage;
    long address;
    SymbolNode* next;
    
    SymbolNode()
    {
        this->identifier = "";
        this->scope = "";
        this->type = "";
        this->lineNo = 0;
        next = NULL;
    }
    SymbolNode(string key, string value, string type, int lineNo)
    {
        this->identifier = key;
        this->scope = value;
        this->type = type;
        this->lineNo = lineNo;
        next = NULL;
    }
};

#endif /* symbol_node_h */
