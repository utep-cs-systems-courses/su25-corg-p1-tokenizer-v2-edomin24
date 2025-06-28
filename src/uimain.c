#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history();  // initialize history list
  char str[100];                   // input buffer
  printf("Welcome!\nPlease enter a sentence or enter:\n'h' for history\n'q' to quit\n'!(num)' to retrieve an item from history.\n");
  
  while (1)
    {
      fputs("$:", stdout);
      fflush(stdout);
      int i = 0;
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
	{
	  if (i < 99){ // prevent buffer overflow
	    str[i++] = (char)c;
	  }
	}
      str[i] = '\0'; // null-terminate the string
      
      if (i == 0) // check if input is empty
	{
	  printf("input null, please add a sentence.\n");
	  continue;
	}
      
      if (str[0] == 'q' && str[1] == '\0') // check if input is "q"
	{
	  printf("Goodbye!\n");
	  break;
	}

      if (str[0] == 'h' && str[1] == '\0') // check if input is "h"
	{
	  printf("History:\n");
	  print_history(history); // print the history
	  continue;
	}

      if (str[0] == '!' && str[1] >= '0' && str[1] <= '9' && str[2] == '\0') // check if input is "!<id>"
	{
	  int id = str[1] - '0'; // convert char to int
	  char *history_str = get_history(history, id); // get history by id
	  if (history_str) {
	    printf("%s\n", history_str);
	  } else {
	    printf("No history found for id %d.\n", id);
	  }
	  continue;
	}

      add_history(history, str); // add input to history
      char **tokens = tokenize(str); // tokenize the input string
      if (tokens) {
	print_tokens(tokens); // print the tokens
	free_tokens(tokens); // free the tokens
      }
    }

  free_history(history);
  return 0;
}
