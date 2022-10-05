# BASIC_interpreter_compiler
##Commit #1##
A compiler and interpreter for the BASIC computer language.

Lexer, parser and interpreter objects created.

There is one data structure that will make up the nodes of the abstract syntax tree, 'Node'.

And a struct data type that defines the token object, 'Token'.

The Lexer processes the string input and returns each token as it finds them.  

As the tokens are returned from the lexer they are passed to the parser. 

The parser object processes the tokens and builds an abstract syntax tree according to each language rules.

The Interpreter then receives the root node that is returned bythe Parser object.

##Commit #2##
Add 'binaryNode' type.
Specify datamembers as public (for now)
Add 'toSymbol' function to translate string literals to lexer usable token identifiers.

Add detection of unary operators '+' and '-'.



