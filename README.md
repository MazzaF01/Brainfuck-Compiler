# Brainfuck-Interpreter
A basic compiler for the brainfuck language.

Write your brainfuck code in "codice.txt" and open the exe file, which will interpreter the code and print out the results.

WHAT IS BRAINFUCK?
Brainfuck is an esoteric programming language which use only 8 characters.
+- Add and subtract 1 in a cell
<> Move by 1 cell in the right or in the left
,. input (,) and output(.)
   Every i/o operation consider the integer value of the cell an ASCII character
   If the user input 6, the cell will not contain 6, but the value for the character '6' (54)
   If a cell contains the number 6 the output will be the character with the ASCII value 6 (ACK, not a visible character)
[] These defines a loop, the character ] check if the current cell is 0 and continues the code, else returns to the
   corrispondent character [ and continus from there
   
HERE IS A CODE THAT SUM TWO NUMBERS
The numbers in input and output should be 1 digit only to work well
  ,                         input
  >+++++ +                  init of a counter 
  [< ----- --- > -]		      subtract 8 to the input until the counter is 0
                            basically subtract 6*8 (48) to the input
                            in the ASCII Table the character 48 is '0',
                            so we are transforming a char to a number.
                            
  ,                         input of the 2nd number in the same cell we were using for the counter
  >+++++ +                  init of another counter
  [< ----- --- > -]         convertion of the char in a number subtracting 48
  
  <                         Returns to the cell of the first input
  
  [>+<-]                    Sum 1 to the 2nd input and subtract 1 to the 1st input until is 0
  +++++ +                   init a counter in the cell of the 2nd input
  [< +++++ +++ > -]         convertion of the number in a char adding 48
  
  <.                        return to the cell with the sum and output
