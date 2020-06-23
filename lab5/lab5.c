/* Daniela De La Torre
   COEN11
   February 7 2019
   This is my code for a linked list for creating reservations at a restaurant
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 20

#define NODE struct node

struct node 	//initializes the structure with name, group, and node
{ char name[20];
  int group;
  NODE *next;
};

NODE *head=NULL;
NODE *tail=NULL;

int check_duplicates(char *username); //prototype for the check_duplicates function

void schedule() //schedule funciton
{int i, groupies, new;
 char username[20];
  
 NODE *p, *q, *temp;
 temp=(NODE *) malloc (sizeof (NODE));
 p=head;
 q=head;
 
 printf("Please enter your name\n");
 scanf("%s", username);
 new = check_duplicates(username);
 if(new==1) //if name repeats they must enter another name
	{printf("There is already a reservation with this name. Pick another name\n");
 	 scanf("%s", username);
	 new = check_duplicates(username);
	 
	}
            
 if(new==0)
	{strcpy(temp->name, username);
 	 printf("Please enter your group size\n");
 	 scanf("%d", &groupies);
 	 temp->group=groupies;
 	 printf("Hello %s, your reservation has been created \n", username);
 	}

 strcpy(temp->name,username);
 temp->group=groupies;

 if (head==NULL) //case for if the list is empty
	 {temp->next=head;
 	  tail=temp;
	  head=temp;
	  return;
	 }
 while(p!=NULL) //case for if the list is not empty
	{q=p;
	 p=p->next;
	}
 temp->next=NULL;
 q->next=temp;
 tail=temp;
	 

 if (temp==NULL)
 	{printf ("no memory\n");
       	 return;
 	}
 
return;
}

int check_duplicates(char *username) //this function checks for duplicates
{NODE *p;
 p=head;
 int flag=0;
 while(p!=NULL)	
	{
	 if(strcmp(username,p->name)==0)  //if the name repeats it returns 1
		{flag=1;
		 p=p->next;
		}
	 else
		{flag=0;
		 p=p->next;
		}
	}
 return flag;
	 
}

void removes()  //remove function
{NODE *p, *q;
 int people;
 p=head;
 q=head;
 printf("How many people are in the reservation you would like to delete?\n");
 scanf("%d", &people);
 if(p==NULL) //case for if the list is empty
	{printf("The list is empty. There is no one to delete\n");
	 return;
	}
 while(p!=NULL)
        {q=p;
         if(p==head && p->group<=people) //case for if we are deleting the head
		{printf("%ss reservation has been deleted\n", p->name);
                 head=p->next;
                 free(p);
		 return;
                 }
	 else 
		{p=p->next;
		 if(p->next!=NULL && p->group<=people) //case for if we are deleting the middle
			{printf("%ss reservation has been deleted\n", p->name);
	 		 q->next=p->next;
			 free(p);
			 return;
			}
	 	 else if(p->next==NULL && p->group<=people) //case for if we are deleting the last node
			{printf("%ss reservation has been deleted\n", p->name);
			 q->next=NULL;
			 tail=q;
			 free(p);
			 return;
			}
      		}
	 }
 return;
}

void listing() //listing function
{NODE *p;
 p=head;
 if(head==NULL)	//if the list is empty it prints all spots are free
	printf("All reservation spots are free\n");
 else
 	while(p!=NULL) //if not empty, it prints all elements of the node
		{printf("%s - party of %d\n", p->name, p->group);
		 p=p->next;
		}
 return;
}

void sizee() //search entry function
{NODE *p;
 int gsize, flag1=0;
 printf("Enter the size of a group\n");
 scanf("%d", &gsize);

 p=head;
 while(p!=NULL)
	{if((p->group)<=gsize)
		 {printf("%s - party of %d\n", p->name, p->group); //prints nodes with a group<=number inputed
		  flag1=1;
		 }
	 p=p->next;
	}
 if(flag1==0)
	printf("There are no reservations with that group size");
 return;
}

int main() //main function
{int option, group;
 char name[20];
 while(1)
  {printf("Press:\n 1 to schedule a reservation\n 2 to cancel a reservation\n 3 to list the reservations\n 4 to see entries\n 0 to quit\n");
   scanf("%d", &option);
   switch(option)
   {case 1:
      {
       schedule();
       break;}
   case 2:
      {
       removes();
       break;}
   case 3:
       {listing();
       break;}
   case 4:
       {
        sizee();
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
