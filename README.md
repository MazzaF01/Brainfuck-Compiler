# Brainfuck-Interpreter
A basic C++ interpeter for the brainfuck language.

Write your brainfuck code in "code.txt" and open the exe file, which will interpreter the code and print out the results.

All the cell rapresent a node, which is a structure with 3 vars: an integer value and two node pointer to the next and to the previous node. A new node is created when (with the > operator) 
