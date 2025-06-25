#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == 't' || c == ' '){
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if (!space_char(c)){
    return 1;
  }
  return 0;
}

char *token_start(char *str) 
{
  if (str == NULL){  
    return NULL;
  }
  while(*str != '\0'){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
  return NULL;
}

char *token_terminator(char *token){
  if (token == NULL){
    return NULL;
  }

  while(*token != '\0'){
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
  
  if(str == NULL){
    return 0;
  }

  while ((str = token_start(str)) != NULL && *str != '\0'){
    count++;
    str = token_terminator(str);
  }

  return count;
} 

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  if (inStr == NULL || len <= 0){
    return NULL;
  }

  char *cp = malloc(len+1);
  if(cp == NULL){
    return NULL;
  }

  for(int i = 0; i < len; i ++){
    cp[i] = inStr[i];
  }

  cp[len] = '\0';
  return cp;
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
    return NULL;
  }

  char **tokens = malloc((count + 1) * sizeof(char *));

  if(tokens == NULL){
    return NULL;
  }

  int i = 0;
  char *s;

  while ((s = token_start(s)) != NULL && *s != '\0'){
    char *t = token_terminator(s);
    short len = t-s;

    tokens[i++] = copy_str(s, len);
    s = t;
  }

  tokens[i] == NULL;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  if (tokens == NULL){
    return;
  }

  for (int i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
}
    

/* Frees all tokens and the vector containing themx. */
 void free_tokens(char **tokens)
 {
   if (tokens == NULL){
     return;
   }

   for (int i = 0; tokens[i] != NULL; i++){
     free(tokens[i]);
   }

   free(tokens);
 }
   
