//
//  Node.h
//  
//
//  Created by Abraham Ayorinde on 9/7/22.
//

#ifndef Node_h
#define Node_h
#include "Token.h"
struct Node{
public:
    Token myNodeToken;
    Node* left;
    Node* right;
    Node* child;
    list<Node*>* compoundStatements;
    list<Node*>* variableDeclarations;
    //const static Token keywords[] = {Token("PROGRAM"), Token(" VAR"), "INTEGER_DIV", "INTEGER", "REAL", "BEGIN", "END"};
    Node()
    {
        myNodeToken.Type = "";
        myNodeToken.Value = 0;
        left = NULL;
        right = NULL;
        child = NULL;
    }
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class binaryNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class unaryNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class compoundNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class assignNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class varNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};

class noOpNode: public Node{
public:
    void addNode(Node* aNode, string nodeType)
    {
        
    }
};
#endif
