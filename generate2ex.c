#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *line;
  if ((line = (char *) malloc(81)) == NULL) 
  {
    printf("Couldn't allocate space for line buffer!\n");
    return 1;
  }
  FILE *fp;
  int temp = strlen(argv[1])-2;
  if(strcmp(argv[temp],".c") != 0)
  {
    strcat(argv[1],".c");
  }
  fp = fopen(argv[1],"w");
  
  if(fp == NULL)
  {
    printf("error opening file\n");
    return 1;
  }
  fputs("#include <stdio.h>",fp);
  fputs("\n",fp);
  fputs("\n",fp);
  fputs("int main(){",fp);
  fputs("\n",fp);
  while(fgets(line,80,stdin))
  {
    fputs("printf(",fp);
    fputs("\"",fp);
    if(line[strlen(line)-1] == '\n')
    {
      line[strlen(line)-1] = '\0';
    }
    fputs(line,fp);
    fputs("\");\n",fp);
  }
  fputs("return 0;\n",fp);
  fputs("}\n",fp);
  fclose(fp);
    
  return 0;
}
