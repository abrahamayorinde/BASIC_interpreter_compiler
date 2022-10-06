# BASIC_interpreter_compiler
#Commit 1
A compiler and interpreter for the BASIC computer language.

Lexer, parser and interpreter objects created.

There is one data structure that will make up the nodes of the abstract syntax tree, 'Node'.

And a struct data type that defines the token object, 'Token'.

The Lexer processes the string input and returns each token as it finds them.  

As the tokens are returned from the lexer they are passed to the parser. 

The parser object processes the tokens and builds an abstract syntax tree according to each language rules.

The Interpreter then receives the root node that is returned bythe Parser object.

#Commit 2
Add 'binaryNode' type.
Specify datamembers as public (for now)
Add 'toSymbol' function to translate string literals to lexer usable token identifiers.

Add detection of unary operators '+' and '-'.

#Commit 3
Add a data member to the 'Node' struct called 'child' which has the type Node*.

Added function prototype to child classes of parent type 'Node'. (classes and structs are interchangeable?)

Added the ability for the to process Unary operators in the 'visit' function of class 'Visitor', the 'factor' and 'traverse' function of class Parser.

Fix the error where the tokenizer loses its place when processing the a string literal into an number.

Removed some debug code in from the 'getToken' function of the 'Lexer' class.

#Commit 4
Fixed the issue with the function 'factor' in Parser that returned the wrong node and as a result some branches of the tree were orphaned.

 



