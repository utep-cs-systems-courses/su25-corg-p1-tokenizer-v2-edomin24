#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Intialize the linked list to keep the history. */
List* init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = 0;  /*new list is empty*/
  return list;

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *currEntry = malloc(sizeof(Item));

  if(!currEntry){
    printf("No history available, Please add a sentence to add to History");
    return;
  }

  char *p = str;   /*find len of str*/
  int len = 0;
  while(*p++) len++;
  
  currEntry ->str = malloc(len + 1) * sizeof(char);

  char *src = str; /*copying the str */
  char *dst = currEntry -> str;
  while((*dst++ = *src++));
  
  currEntry -> next = 0;

  if(!list -> root){ 
    list -> root = currEntry;
    currEntry -> id = 1;
  } else{
    Item *prevEntry = list -> root;
    while (prevEntry ->next){
    prevEntry = prevEntry -> next;
    }
    currEntry -> next = prevEntry;
    currEntry -> id = prevEntry ->id +1;
  }
}   
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  if(!list){
    return 0;
  }

  Item *p = list -> root;
  while (p){
    if (p -> id == id){
      return p _> str;
    }

    p = p -> next;
  }

  return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list -> root;
  while(temp){
    printf("%dL %s\n", temp ->id, temp -> str);
    temp = temp -> next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *currEntry = list -> root;
  while(currEntry){
    Item *nextEntry = currEntry -> next;
    free(currEntry -> str);
    free(currEntry);
    currEntry = nextEntry;
  }

  free(list);
}
