#include <stdlib.h>
#include <stdio.h>

int main()
{
  int ran_num, user_val[10], i, count = 0;
  ran_num = rand() % 1000 + 1; // makes random number
  printf("guess the value\n"); // ask the user to guess
    for(i = 0; i < 10; i++)
    {
      scanf("%d",&user_val[i]);
      count++;
      if(user_val[i] < ran_num)
      {
	printf("Too low\n");
      }
      if(user_val[i] > ran_num)
      {
	printf("Too high\n");
      }
      if(user_val[i] == ran_num)
      {
	printf("You guessed correct\n");
	break;
      }
    }
    if(user_val[count-1] != ran_num)
    {
      printf("The random number was:%d\n", ran_num);
      for(i = 0; i < count; i++) // loop through the values
      {
	printf("the values you guessed: %d\n",user_val[i]);
      }
    }
  return 0;
}