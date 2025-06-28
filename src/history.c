#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Intialize the linked list to keep the history. */
List* init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = 0;  /*new list is empty*/
  return list;
}
/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *currEntry = malloc(sizeof(Item));
  char *p = str;   /*find len of str*/
  int len = 0;
  while(*p)
    {
      len++;
      p++;
    }
  
  currEntry ->str = malloc((len + 1) * sizeof(char));
  char *src = str; /*copying the str */
  char *dst = currEntry -> str;
  while(*src)
    {
      *dst++ = *src++;
    }
  
  *dst = '\0';
  currEntry -> next = 0;

  if(!list -> root){ 
    currEntry -> id = 1;
    list -> root = currEntry;
  } else{
    Item *prevEntry = list -> root;
    while (prevEntry ->next)
      {
	prevEntry = prevEntry -> next;

      }
    
    currEntry -> id = prevEntry ->id +1;
    currEntry -> next = prevEntry;
  }
}   
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list -> root;
  while (temp){
    if (temp -> id == id){
      return temp -> str;
    }
    temp = temp -> next;
  }
  printf("No item found with id %d.\n", id);
  return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  if (!list || !list -> root)
    {
      printf("History is empty, please add a sentence.\n");
      return;
    }
  
  Item *temp = list -> root;
  while(temp){
    printf("%d | %s\n", temp ->id, temp -> str);
    temp = temp -> next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  if(!list) return;
  Item *currEntry = list -> root;
  while(currEntry){
    Item *nextEntry = currEntry -> next;
    free(currEntry -> str);
    free(currEntry);
    currEntry = nextEntry;
  }
  free(list);
}  
