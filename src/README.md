
Project 1: Tokenizer
====================
The c file of Tokenizer processes a given string and seperates them into
tokens. Some key behaviour exhibited by the program consists of:

  - Given a String, skip over its white space chars and ignore leading or
    trailing spaces between each word in the given string from user.
  - Allocates memory dynamically for each of the tokens using malloc. The size
    in memory is calculated by the amount of chars (plus one for the null
    terminator) in a token times the size of its type.

### Functions

char *token_start(char *str);
  - This function returns a pointer of type char to determine where in the
    current str does the word start.

char **tokenize(char *str);
 - using functions within this file (token_start, token_terminator, etc) to
 correctly count the amount of tokens within a string.

