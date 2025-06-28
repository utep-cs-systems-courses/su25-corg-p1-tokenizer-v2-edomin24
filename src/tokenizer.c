#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  return (c == '\t' || c == ' ');
}

int non_space_char(char c)
{
  return !space_char(c);
}

char *token_start(char *str) 
{
  while( *str && space_char(*str))
    {
      str++;
    }

  if(*str)
    {
      return str;
    }
  else
    {
      return 0;
    }
}

char *token_terminator(char *token)
{
  while(*token && non_space_char(*token))
    {
      token++;
    }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int count = 0;
  char *temp = token_start(str);
  while (temp)
    {
      count++;
      char * end = token_terminator(temp);
      if(*end)
	{
	  temp = token_start(end);
	}

      else{
	break;
      }
    }
  return count;
}
 
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *newStr = malloc((len + 1) * sizeof(char));
  int i = 0;
  while(i < len && *(inStr + i))
    {
      *(newStr + i) = *(inStr + i);
      i++;
    }
  *(newStr+ i) = '\0'; /*Null terminate*/
  return newStr;
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
  char *start = token_start(str);

  while(start)
    {
      char *end = token_terminator(start);
      tokens[i] = copy_str(start, end - start);
      i++;
      if(*end){
	start = token_start(end);
      }
      else{
	break;
      }
    }
  tokens[i] = '\0';
  return tokens;
}
 
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  if (!tokens) return;
  for (int i = 0; tokens[i] != 0; i++){
    printf("[%d]: '%s'\n",i, tokens[i]);
  }
}
    

/* Frees all tokens and the vector containing themx. */
 void free_tokens(char **tokens)
 {
   if (!tokens) return;
   for (int i = 0; tokens[i] != 0; i++){
     free(tokens[i]);
   }
   free(tokens);
 }
  
