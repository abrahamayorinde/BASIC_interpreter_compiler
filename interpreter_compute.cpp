
#include <iostream>
#include <string>

//"MULTIPLY", "DIVIDE", "ADD", "SUBTRACT", "LPARENTH", "RPARENTH",
using namespace std;

bool isdigit(char digit);
bool nearEnd(int place, int end);
string toSymbol(string word);

struct Token{
    string Type;
    int Value;
};

struct Node{
public:
    Token myNodeToken;
    Node* left;
    Node* right;
    Node* child;
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
    Node* left;
    Node* right;
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

class Lexer{
public:
    string inputText;
    int place;
    int end;
    Token thisToken;
    int tokencount;
    
    void getInput(string text)
    {
        inputText = text;
        place = 0;
        end = inputText.length();
        tokencount = 0;
    }
    
    char currentSymbol()
    {
        if(place<end)
        {
            return inputText.at(place);
        }
        else
        {
            return inputText.at(end-1);
        }
    }
    
    Token getToken()
    {
        thisToken.Value = 0;
        thisToken.Type = "";
        string literalValue = "";
        cout<<endl;
        cout<<"getToken: place: "<<place<<endl;
        if(place < end)
        {
            tokencount++;
            cout<<"getToken: count: "<<tokencount<<endl;
            while(isspace(inputText.at(place)) && place<end)
            {
                if(nearEnd(place,end))
                {
                    place++;
                    goto labelout;
                }
                else
                {
                    place++;
                }
            }
            if( isdigit(inputText.at(place)) and (place<end) )
            {
                while(isdigit(inputText.at(place)) and (place<end) )
                {
                    literalValue.append(1,inputText.at(place));
                    if( place+1 >= end)
                    {
                        thisToken.Type = "INTEGER";
                        thisToken.Value = stoi(literalValue);
                        cout<<"getToken: value at end: "<<thisToken.Value<<endl;
                        place++;
                        goto labelout;
                    }
                    thisToken.Value = stoi(literalValue);
                    place++;
                }
                thisToken.Type="INTEGER";
                thisToken.Value = stoi(literalValue);
                cout<<"getToken: value before end: "<<thisToken.Value<<endl;
                goto labelout;
            }
            if(inputText.at(place) == '+')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "ADD";
                place++;
                goto labelout;
            }
            if(inputText.at(place) == '-')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "SUBTRACT";
                place++;
                goto labelout;
            }
            if(inputText.at(place) == '*')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "MULTIPLY";
                place++;
                goto labelout;
            }
            if(inputText.at(place) == '/')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "DIVIDE";
                place++;
                goto labelout;
            }
            if(inputText.at(place) == '(')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "LPARENTH";
                place++;
                goto labelout;
            }
            if(inputText.at(place) == ')')
            {
                cout<<"getToken: "<<inputText.at(place)  <<endl;
                thisToken.Type = "RPARENTH";
                place++;
                goto labelout;
            }
            labelout:
            return thisToken;
        }
        else
        {
            return thisToken;
        }
    }
};

class Parser
{
public:
    /*"""term : factor ((MUL | DIV) factor)*"""*/
    Lexer thislexer;
    Token currentToken;
    Node astHead;
    Node* astPointer;
    string cursorTokenCharType;
    int i;

    Parser()
    {
        //astPointer = new Node;
    }
    void getLexer(Lexer lexer)
    {
        thislexer = lexer;
        i=0;
    }
     
    void startLexer()
    {
        currentToken = thislexer.getToken();
        cursorTokenCharType = getcursorSymbol();
    }
    
    char getcursorSymbol()
    {
        return thislexer.currentSymbol();
    }
    
    void eat(string tokenType)
    {
        if(currentToken.Type == tokenType)
        {
            cout<<"PARSER: EATEN AND DIGESTED: "<<currentToken.Type<<endl;
            currentToken = thislexer.getToken();
            cout<<endl;
            cout<<"PARSER: JUST EATEN TOKEN : "<<currentToken.Type<<endl;
        }
        else
        {
            cout<<":Error:"<<endl;
        }
    }
    
    void traverse(Node* astTreePointer)
    {
        if((astTreePointer->myNodeToken.Type == "UNARY +") || (astTreePointer->myNodeToken.Type == "UNARY -"))
        {
            cout<<"TRAVERSE - Type: "<<astTreePointer->myNodeToken.Type<<endl;
            cout<<"TRAVERSE - Value: "<<astTreePointer->myNodeToken.Value<<endl;
            traverse(astTreePointer->child);
        }
        else
        {
            if (astTreePointer->left != NULL)
            {
                traverse(astTreePointer->left);
            }
         
            cout<<"TRAVERSE - Type: "<<astTreePointer->myNodeToken.Type<<endl;
            cout<<"TRAVERSE - Value: "<<astTreePointer->myNodeToken.Value<<endl;
         
            if (astTreePointer->right != NULL)
            {
                traverse(astTreePointer->right);
            }
        }
    }

    Node* factor( )
    {
        Node* astNode;
        Node* newNode;
        
        Token current = currentToken;
        bool change = false;

        cout<<"PARSER: Factor Token Type: "<<currentToken.Type<<endl;
        if( currentToken.Type == "ADD")
        {
            newNode = new unaryNode;
            eat("ADD");
            newNode->myNodeToken.Value = 0;
            newNode->myNodeToken.Type = "UNARY +";
            newNode->child = factor();
            astNode = newNode;
        }
        if( currentToken.Type == "SUBTRACT")
        {
            newNode = new unaryNode;
            eat("SUBTRACT");
            newNode->myNodeToken.Value = 0;
            newNode->myNodeToken.Type = "UNARY -";
            newNode->child = factor();
            astNode = newNode;
        }
        if( currentToken.Type == "INTEGER")
        {
            //
            cout<<"PARSER: token #:"<<i+1<<endl;
            cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
            cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
            i++;
            //
            astNode = new Node;
            astNode->myNodeToken.Value = currentToken.Value;
            astNode->myNodeToken.Type = currentToken.Type;
            astNode->left = NULL;
            astNode->right = NULL;
            eat("INTEGER");

            return astNode;
        }
        
        if( currentToken.Type == "LPARENTH")
        {
            //
            cout<<"PARSER: token #:"<<i+1<<endl;
            cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
            cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
            cout<<endl;
            i++;
            //
            eat("LPARENTH");
            astNode = expression();
            eat("RPARENTH");
            return astNode;
        }
        
        return astNode;
    }
    
    Node* term( )
    {
        Node* leftNode;
        Node* newNode;
        bool change = false;
        Token current = currentToken;
        
        leftNode = factor();
        
        cout<<"PARSER: Term Token Type: "<<currentToken.Type<<endl;

        while( (currentToken.Type == "MULTIPLY") || (currentToken.Type == "DIVIDE") )
        {
            change = true;
            if(currentToken.Type == "MULTIPLY")
            {
                //
                cout<<"PARSER: token #:"<<i+1<<endl;
                cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
                cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
                i++;
                //
                newNode = new Node;
                newNode->myNodeToken.Type = "MULTIPLY";
                newNode->left = leftNode;
                eat("MULTIPLY");
                newNode->right = factor();
                leftNode = newNode;
            }
            if(currentToken.Type == "DIVIDE")
            {
                //
                cout<<"PARSER: token #:"<<i+1<<endl;
                cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
                cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
                i++;
                //
                newNode = new Node;
                newNode->myNodeToken.Type = "DIVIDE";
                newNode->left = leftNode;
                eat("DIVIDE");
                newNode->right = factor();
                leftNode = newNode;
            }
        }
        return leftNode;
    }
    
    /*
     pre: currentToken.Type exists
     post:returns the root node of the abstract syntax token tree
     */
    Node* expression()
    {
        Node* leftNode;
        Node* newNode;// = new Node;
        bool change = false;
        
        leftNode = term();

        cout<<"PARSER: Expression Token Type: "<<currentToken.Type<<endl;

        while ((currentToken.Type == "ADD") || (currentToken.Type == "SUBTRACT"))
        {
            change = true;
            if(currentToken.Type == "ADD")
            {
                //
                cout<<"PARSER: token #:"<<i+1<<endl;
                cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
                cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
                i++;
                //
                newNode = new Node;
                newNode->left = leftNode;
                newNode->myNodeToken.Type = "ADD";
                eat("ADD");
                newNode->right = term();
                leftNode = newNode;

            }
            if(currentToken.Type == "SUBTRACT")
            {
                //
                cout<<"PARSER: token #:"<<i+1<<endl;
                cout<<"PARSER: Token - Type: "<<currentToken.Type<<endl;
                cout<<"PARSER: Token - Value: "<<currentToken.Value<<endl;
                i++;
                //
                newNode = new Node;
                newNode->left = leftNode;
                newNode->myNodeToken.Type = "SUBTRACT";
                eat("SUBTRACT");
                newNode->right = term();
                leftNode = newNode;
            }
        }
        
        return leftNode;
    }
};
class Visitor
{
public:
    /*"""term : factor ((MUL | DIV) factor)*"""*/
    int result;
    string rpn;
    string lisp;
    
    int visit(Node* asTree)
    {
        
        if(asTree->myNodeToken.Type == "UNARY +")
        {
            result = visit(asTree->child);
        }
        if(asTree->myNodeToken.Type == "UNARY -")
        {
            result = -visit(asTree->child);
        }
        if(asTree->myNodeToken.Type == "ADD")
        {
            result = visit(asTree->left) + visit(asTree->right);
        }
        if(asTree->myNodeToken.Type == "SUBTRACT")
        {
            result = visit(asTree->left) - visit(asTree->right);
        }
        if(asTree->myNodeToken.Type == "MULTIPLY")
        {
            result = visit(asTree->left) * visit(asTree->right);
        }
        if(asTree->myNodeToken.Type == "DIVIDE")
        {
            result = visit(asTree->left) / visit(asTree->right);
        }
        if(asTree->myNodeToken.Type == "INTEGER")
        {
            return asTree->myNodeToken.Value;
        }
        return result;
    }
    
    void rpnTranslator(Node* asTree)
    {
        if(asTree->left!=NULL)
        {
            if(asTree->left->myNodeToken.Type == "INTEGER")
            {
                rpn.append(to_string(asTree->left->myNodeToken.Value));
            }
            else
            {
                rpnTranslator(asTree->left);
            }
        }
 
        if(asTree->right!=NULL)
        {
            if(asTree->right->myNodeToken.Type == "INTEGER")
            {
                rpn.append(to_string(asTree->right->myNodeToken.Value));
            }
            else
            {
                //The type of token at this particular node is, by inspection, an operator
                rpnTranslator(asTree->right);
            }
        }
 
        if((asTree != NULL) && (asTree->myNodeToken.Type != "INTEGER"))
        {
            rpn.append(toSymbol(asTree->myNodeToken.Type));
        }
    }
    
    void lispTranslator(Node* asTree)
    {
        lisp.append("(");
        lisp.append(toSymbol(asTree->myNodeToken.Type));
        
        if(asTree->left!=NULL)
        {
            if(asTree->left->myNodeToken.Type == "INTEGER")
            {
                lisp.append(to_string(asTree->left->myNodeToken.Value));
            }
            else
            {
                lispTranslator(asTree->left);
            }
        }
        
        if(asTree->right!=NULL)
        {
            if(asTree->right->myNodeToken.Type == "INTEGER")
            {
                lisp.append(to_string(asTree->right->myNodeToken.Value));
            }
            else
            {
                lispTranslator(asTree->right);
            }
        }
        lisp.append(")");
    }
    
    void printrpn()
    {
        cout<<rpn<<endl;
    }
    
    void printlisp()
    {
        cout<<lisp<<endl;
    }
};


class Interpreter
{
public:
    /*"""term : factor ((MUL | DIV) factor)*"""*/
    Lexer thislexer;
    Token currentToken;
    string cursorTokenCharType;

    void getLexer(Lexer lexer)
    {
        thislexer = lexer;
    }
     
    void startLexer()
    {
        currentToken = thislexer.getToken();
        cursorTokenCharType = getcursorSymbol();
    }
    
    char getcursorSymbol()
    {
        return thislexer.currentSymbol();
    }
    
    void eat(string tokenType)
    {
        Token current = currentToken;
        if(currentToken.Type == tokenType)
        {
            currentToken = thislexer.getToken();
        }
        else
        {
            cout<<":Error:"<<endl;
        }
    }

    int factor()
    {
        int result;
        Node currentNode;
        Token current = currentToken;
            
        if( currentToken.Type == "INTEGER")
        {
            eat("INTEGER");
            return current.Value;
        
        }
        else if( currentToken.Type == "LPARENTH")
        {
            eat("LPARENTH");
            result = expression();
            eat("RPARENTH");
            return result;
        }
        return result;
    }
    
    int term()
    {
        int result = factor();
        Token current = currentToken;
        
        cout<<"Term Token Type: "<<currentToken.Type<<endl;
        while( (currentToken.Type == "MULTIPLY") || (currentToken.Type == "DIVIDE") )
        {
            if(currentToken.Type == "MULTIPLY")
            {
                eat("MULTIPLY");
                result = result * factor();
            }
            if(currentToken.Type == "DIVIDE")
            {
                eat("DIVIDE");
                result = result / factor();
            }
        }
        return result;
    }
    
    int expression()
    {
        int result = term();
        
        while ((currentToken.Type == "ADD") || (currentToken.Type == "SUBTRACT"))
        {
            if(currentToken.Type == "ADD")
            {
                eat("ADD");
                result = result + term();
            }
            if(currentToken.Type == "SUBTRACT")
            {
                eat("SUBTRACT");
                result = result - term();
            }
        }
        return result;
    }
};

int main()
{
    string prompt = "Enter an expression to be evalauted:\n";
    string answer;
    Lexer thisLexer;
    Lexer thisLexer2;
    
    Interpreter interpreter;
    Parser parser;
    Visitor theVisitor;
    Node* testNode;
    /*
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;
    Node* node4 = new Node;
    Node* node5 = new Node;
    */
    
    cout<<prompt;
    
    getline(cin,answer);
    
    //thisLexer.getInput(answer);
    thisLexer2.getInput(answer);
    
    //interpreter.getLexer(thisLexer);
    
    //interpreter.startLexer();
    
    //cout<<interpreter.expression()<<endl;

    parser.getLexer(thisLexer2);
    
    parser.startLexer();
    
    testNode =  parser.expression();
    
    parser.traverse(testNode);
    
    
    //parser.traverse(testNode);

    cout<<"Here is the result: "<<theVisitor.visit(testNode)<<endl;
    
    theVisitor.rpnTranslator(testNode);
    
    theVisitor.lispTranslator(testNode);

    
    theVisitor.printrpn();
    
    theVisitor.printlisp();
    //cout<<endl;
    //theVisitor.lispTranslator(testNode);

    //parser.traverse(testNode);

    /*
    node1->myNodeToken.Type = "INTEGER";
    node1->myNodeToken.Value = 2;
    node1->left = NULL;
    node1->right = NULL;
    
    node2->myNodeToken.Type = "*";
    node2->myNodeToken.Value = 0;
    node2->left = node1;
    node2->right = node3;

    node3->myNodeToken.Type = "INTEGER";
    node3->myNodeToken.Value = 7;
    node3->left = NULL;
    node3->right = NULL;
    
    node4->myNodeToken.Type = "+";
    node4->myNodeToken.Value = 0;
    node4->left = node2;
    node4->right = node5;
    
    node5->myNodeToken.Type = "INTEGER";
    node5->myNodeToken.Value = 3;
    node5->left = NULL;
    node5->right = NULL;
    
    parser.traverse(node4);
    */

     
    return 0;
}


bool isdigit(char digit)
{
    if(digit == '1' || digit == '2' || digit == '3' || digit == '4' || digit == '5' || digit == '6' || digit == '7' || digit == '8' || digit == '9' || digit == '0')
    {
        return true;
    }
    return false;
}

bool nearEnd(int place, int end)
{
    if( (place+1) >= end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string toSymbol(string word)
{
    if(word == "ADD")
    {
        return "+";
    }
    if(word == "SUBTRACT")
    {
        return "-";
    }
    if(word == "DIVIDE")
    {
        return "/";
    }
    if(word == "MULTIPLY")
    {
        return "*";
    }
    return "";
}
