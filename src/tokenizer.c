#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  return (c == 't' || c == ' ');
}

int non_space_char(char c)
{
  return !space_char(c);
}

char *token_start(char *str) 
{
  while(*str){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
  return 0;
}

char *token_terminator(char *token)
{
  while(*token){
    if(space_char(*token)){
      return token;
    }

    token++;
  }

  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int count = 0;
 
  while ((str = token_start(str))){
    count++;
    str = token_terminator(str);
  }
  return count;
} 

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{

  char *cp = malloc(len+1) * sizeof(char);
  char *strStart= cp;
  
  while(len--){
    *cp++ = *inStr++;
  }

  *cp = 0;
  return strStart;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int count = count_tokens(str);
  if (count == 0){
    return 0;
  }

  char **tokens = malloc((count + 1) * sizeof(char *));
  int i = 0;
  char *s;

  while ((s = token_start(str))){
    char *t = token_terminator(s);
    short len = t-s;
    tokens[i++] = copy_str(s, len);
    str = t;
  }

  tokens[i] = 0;
  return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  if (!tokens) return;
  for (int i = 0; tokens[i]; i++){
    printf("%s\n", tokens[i]);
  }
}
    

/* Frees all tokens and the vector containing themx. */
 void free_tokens(char **tokens)
 {
   if (!tokens) return;
   for (int i = 0; tokens[i]; i++){
     free(tokens[i]);
   }
   free(tokens);
 }
   
