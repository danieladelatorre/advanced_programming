#include <stdio.h>
#include <string.h>
#define M 10
#define N 20

typedef union occasions //creates a union called EVENT
{char name[20];
 int years;
 float average_age;
}EVENT;

typedef struct entry //creates a structure called ENTRY
{ char name[20];
  int group;
  int special_occasion;
  int flag;
  EVENT event;
}ENTRY;

ENTRY list[10]; //creates an array of structures
int counter=0; // global counter

int check_duplicates(char *username); //calls the function check_duplicates to use in the schedule function

void schedule()
{int i, groupies, new, flag2, a_years;
 char username[20], bday_name[20];
 float avg_age;
 ENTRY *p=list; //pointer points to the first position is the array of structures
 
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
	 
	 if(new==1) //if check_duplicates returns 1, they need to enter another name
	 	{printf("There is already a reservation with this name. Pick another name\n");
		scanf("%s", username);
         	new = check_duplicates(username);}
	 	
	 if(new==0) //if check_duplicates returns 0, they must enter more information
	 	{strcpy(p->name, username);
         	 printf("Please enter your group size\n");
         	 scanf("%d", &groupies);
		 p->group=groupies;
		 printf("Is there a special occasion?\nPress:\n 1 for a Birthday\n 2 for an Anniversary\n 0 for no special occasion\n"); //asks the user if there is any special occassion
		 scanf("%d", &flag2);
		 p->flag=flag2;
		 if(p->flag==1) //if they enter 1, they must enter the name of the birthday person
			{printf("What is the name of the birthday person\n");
			scanf("%s",bday_name);
                        strcpy(p->event.name, bday_name);
			}
		 else if(p->flag==2) //if they enter 2, they must enter the number of years
			{printf("Please enter the number of years\n");
			 scanf("%d",&a_years);
                         p->event.years=a_years;
			}
		 else
			{printf("Enter the average age of the group\n"); //they must enter the average age of the group
			 scanf("%f",&avg_age);
			 p->event.average_age=avg_age;
			}
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
		flag=1; //if there is a duplicate it returns 1 if not it returns 0
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
                        {strcpy(p->name, (p+1)->name); // shifts the reservation name up one
                         p->group=(p+1)->group; //shifts the size of the group up one
			 if(p->flag==1)
				{strcpy(p->event.name, (p+1)->event.name); //shifts the birthday name up one space
				 p->flag=(p+1)->flag; //shifts the flag up one space
				}
			 if(p->flag==2)
				{p->event.years=(p+1)->event.years; //shifts the number of years up one space
				 p->flag=(p+1)->flag; //shifts the flag up one space
				}
			 if(p->flag==0)
                                {p->event.years=(p+1)->event.average_age; //shifts the average age up one space
				 p->flag=(p+1)->flag; //shifts the flag up one space
				}
                        }
                 counter--; //decrements the counter
                 
                }
        }
}

void listing()
{ENTRY *p=list;
 int i;
 if(counter==0)
	printf("All reservation spots are free"); //if the list is empty it prints all spots are free
 else
	for(i=0;i<counter;i++,p++)
 		{if(p->flag==1) //if flag is 1 it prints the birthday information
			printf("%ss reservation, %ss Birthday - party of %d\n", p->name, p->event.name, p->group);
		 else if(p->flag==2) //if flag is 2 it prints the anniversary information
			printf("%ss %dth Anniversary  - party of %d\n", p->name, p->event.years, p->group);
		 else //prints the information of the reservation
			printf("%s party of %d, average age: %f\n", p->name, p->group, p->event.average_age);
		}
 return;
}

void sizee()
{ENTRY *p=list;
 int i, gsize;
 printf("Enter the size of a group\n");
 scanf("%d", &gsize);
 for(i=0;i<counter;i++,p++)
	{if((p->group)<=gsize)
		{if(p->flag==1) //if flag is 1 it prints the birthday information
			printf("%ss reservation, %ss Birthday - party of %d\n", p->name, p->event.name, p->group);
		 else if(p->flag==2) //if flag is 2 it prints the anniversary information
                        printf("%ss %dth Anniversary  - party of %d\n", p->name, p->event.years, p->group);
		 else //prints the information of the reservation
                        printf("%s party, average age: %f - party of %d\n", p->name, p->event.average_age, p->group);
		}
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
      {schedule(); //calls the schedule function
       break;}
   case 2:
      {removes(); //calls the remove function
       break;}
   case 3:
       {listing(); //calls the listing function
       break;}
   case 4:
       {sizee(); //calls the sizee function
       break;}
   case 0:
    { return 1; //breaks out of the loop
      break;}
   default:
     {printf("The option you entered is invalid");
      break;}
    }
  }
}
