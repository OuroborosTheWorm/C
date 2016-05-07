#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  char *line;
  char*  preline;
  char* postline;
  FILE *fp;

  if (argc != 2)
  {
    printf("no word specified\n");
    return 1;
  }
  if ((line = (char *) malloc(81)) == NULL)
  {
    printf("Couldn't allocate space for line buffer!\n");
    return 1;
    
  }
  if ((preline = (char *) malloc(81)) == NULL)
  {
    printf("Couldn't allocate space for line buffer!\n");
    return 1;
    
  }
  if ((postline = (char *) malloc(81)) == NULL)
  {
    printf("Couldn't allocate space for line buffer!\n");
    return 1;
    
  }
  fp = fopen("words.txt","r");
  if(fp == NULL)
  {
    printf("error opening file\n");
    return 1;
  }
  int temp;
  while(fgets(line,80,fp))
  {
    temp = strlen(argv[1]);
    argv[temp] = '\0';
    if(strcmp(line,argv[1]) == 0)
    {
      printf("the word:%s exists\n",line);
      printf("word:%s\n",line);
      fgets(postline,80,fp);
    }
    break;
    preline = line;
  }
  printf("previous line:%s\nline after:%s\n",preline,postline);
  fclose(fp);
  return 0;
}