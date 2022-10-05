# BASIC_interpreter_compiler

A compiler and interpreter for the BASIC computer language.

Lexer, parser and interpreter objects created.

There is one data structure that will make up the nodes of the abstract syntax tree, 'Node'.

And a struct data type that defines the token object, 'Token'.

The Lexer processes the string input and returns each token as it finds them.  

As the tokens are returned from the lexer they are passed to the parser. 

The parser object processes the tokens and builds an abstract syntax tree according to each language rules.

The Interpreter then receives the root node that is returned bythe Parser object.