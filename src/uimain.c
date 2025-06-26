#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char str [100];
  printf("Enter your sentence bro\n");
  while(1)
    {
      printf(">:");
      fgets(str, sizeof(str), stdin);

      printf("%s", str);
    }

  return 0;
}

