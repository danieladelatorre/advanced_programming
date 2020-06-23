#include <stdio.h>
#include <string.h>
#define M 10
#define N 20

typedef struct entry
{ char name[20];
  int group;
}ENTRY;

ENTRY list[10];
int counter=0;

int check_duplicates(char *username);

void schedule()
{int i, groupies, new;
 char username[20];
 ENTRY *p=list;
 
 for(i=0;i<counter;i++)
 	p++;
 if (counter==10) //if the array is full, it will print that the array is full
        {printf("The waitlist is full. Come back tomorrow\n");
         return;
        }
 else
	{printf("Please enter your name\n");
         scanf("%s", username);
	 new = check_duplicates(username);
	 
	 if(new==1)
	 	{printf("There is already a reservation with this name. Pick another name\n");
		scanf("%s", username);
         	new = check_duplicates(username);}
	 	
	 if(new==0)
	 	{strcpy(p->name, username);
         	 printf("Please enter your group size\n");
         	 scanf("%d", &groupies);
		 p->group=groupies;
        	 counter++;
        	 printf("Hello %s, your reservation has been created \n", username);
		}
        }
return;
}

int check_duplicates(char *username)
{ENTRY *p=list;
 int i, flag=0;
 for(i=0;i<counter;i++,p++)
	{
	 if(strcmp(username,p->name)==0)
		flag=1;
	 else
		flag=0;
	}
 return flag;
	 
}

void removes()
{ENTRY *p=list;
 int i, people;
 printf("How many people are in the reservation you would like to delete?\n");
 scanf("%d", &people);
 for(i=0;i<counter;i++,p++)
        {if(people==p->group || p->group<people)
                {printf("%ss reservation has been cancelled\n", p->name);
                 for(;i<counter;i++,p++)
                        {strcpy(p->name, (p+1)->name);
                         p->group=(p+1)->group;
                        }
                 counter--;
                 
                }
        }
}

void listing()
{ENTRY *p=list;
 int i;
 if(counter==0)
	printf("All reservation spots are free");
 else
	for(i=0;i<counter;i++,p++)
 		printf("%s - party of %d\n", p->name, p->group);
 return;
}

void sizee()
{ENTRY *p=list;
 int i, gsize;
 printf("Enter the size of a group\n");
 scanf("%d", &gsize);
 for(i=0;i<counter;i++,p++)
	{if((p->group)<=gsize)
		printf("%s - party of %d\n", p->name, p->group);
	}
 return;
}

int main()
{int option;
 while(1)
  {printf("Press:\n 1 to schedule a reservation\n 2 to cancel a reservation\n 3 to list the reservations\n 4 to see entries\n 0 to quit\n");
   scanf("%d", &option);
   switch(option)
   {case 1:
      {schedule();
       break;}
   case 2:
      {removes();
       break;}
   case 3:
       {listing();
       break;}
   case 4:
       {sizee();
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
