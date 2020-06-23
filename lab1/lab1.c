#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dividing(); //initializes the function dividing so the main function can use it

int main(void)
{srand((int)time(NULL));
 int i, counter=0, useranswer;
 for(i=0;i<10;i++) //a loop so that the function will give ten questions
 {int c = rand()%13; //assigns random numbers between 0 and 12 to the quotient
  int b = rand()%12+1; //assigns random numbers between 1 and 12 for the divisor
  int a = b*c;
  printf("What is %d / %d?\n", a, b);
  useranswer=dividing(a,b); //gets the result of whether the user's guess was right or wrong from the function dividing
  if (useranswer==1) {
     printf("Correct!\n");
     counter++;
    }
  else
    {printf("Wrong! The correct answer is %d \n", c);}
 }
 printf("Your total score is %d0 percent\n", counter); //prints the total score

}

int dividing(int a, int b)
{int guess, answer;
 answer=a/b;
 scanf("%d", &guess);
 if(guess==answer) //if the answer is right, it will return 1, if not it will return 0
  {return 1;
  }
 else
   {return 0;}

}
