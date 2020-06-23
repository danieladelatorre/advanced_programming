#include <stdio.h>
#define M 10
#define N 20
#include <string.h>
char x[M][N];
int group[M];
int counter=0;

void schedule()
{int i;
 char name[20];
 if (counter==10) //if the array is full, it will print that the array is full
	{printf("The waitlist is full. Come back tomorrow\n");
	 return;
        }
 else
	{printf("Please enter your name\n");
	 scanf("%s", x[counter]);
	 printf("Please enter your group size\n");
	 scanf("%d", &group[counter]);
	 counter++;
	 printf("Hello %s, your reservation has been created \n", name);
	}
return;
}

void removes()
{int i,flag=0, people;
 char name[20];
 printf("How many people are in the reservation you would like to delete?\n");
 scanf("%d", &people);
 for(i=0;i<counter;i++)
	{if(people==group[i] || group[i]<people)
		{printf("%ss reservation has been cancelled\n", x[i]);
		 for(;i<counter;i++)
			{strcpy(x[i], x[i+1]);
			 group[i]=group[i+1];
			 flag=1;
			}
		 x[counter][0]='\0';
		 counter--;	
		 
		}
	}
 if(flag==0)
 	printf("Group size not found\n");
}


void list()
{int i,j;
 if(counter==0)
	printf("All the reservation slots are free");
 else
	{j=0;
	 for(i=0;i<10;i++)
		{if(x[i][j]!='\0')
			printf("%s - party of %d\n", x[i], group[i]);
		 else
			printf("free\n");
		}
	}
}

int main(void)
{int option, flag=0, i, j;
char name[20];
x[0][0]='\0';
x[1][0]='\0';
x[2][0]='\0';
x[3][0]='\0';
x[4][0]='\0';
x[5][0]='\0';
x[6][0]='\0';
x[7][0]='\0';
x[8][0]='\0';
x[9][0]='\0';
while(1)
  {printf("Press:\n 1 to schedule a reservation\n 2 to cancel a reservation\n 3 to list the reservations\n 0 to quit\n");
   scanf("%d", &option);
   switch(option)
   {case 1:
      {schedule();
       break;}
   case 2:
      {removes();
       break;}
   case 3:
       {list();
       break;}
   case 0:
    { return 1;
      break;}
   default:
     {printf("The option you entered is invalid");
      break;}
    }
  }
}


