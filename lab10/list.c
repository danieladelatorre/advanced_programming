/* Daniela De La Torre
   COEN11
   February 18 2019
   This is my code for a linked list for creating reservations at a restaurant
*/

#include "makefilefile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#define M 10
#define N 20


void schedule(char *username, int groupies) //schedule function
{int i, new, index;
  
 NODE *p, *q, *temp;
 temp=(NODE *) malloc (sizeof (NODE));
 temp->group=groupies;
 strcpy(temp->name,username);
 temp->group=groupies;
 if(temp->group==1 || temp->group==2)
 	index=0;
 else if(temp->group==3 || temp->group==4)
	index=1;
 else if(temp->group==5 || temp->group==6)
	index=2;
 else 
	index=3;
 p=q=x[index].head;
 if (x[index].head==NULL) //case for if the list is empty
	 {temp->next=x[index].head;
 	  x[index].tail=temp;
	  x[index].head=temp;
	  return;
	 }
 while(p!=NULL) //case for if the list is not empty
	{q=p;
	 p=p->next;
	}
 temp->next=NULL;
 q->next=temp;
 x[index].tail=temp;
 	 

 if (temp==NULL)
 	{printf ("no memory\n");
       	 return;
 	}
 
return;
}

int check_duplicates(char *username) //this function checks for duplicates
{NODE *p;
 int flag=0, i;
 for(i=0; i<4; i++)
	{p=x[i].head;
 	 while(p!=NULL)	
		{
		 if(strcmp(username,p->name)==0)  //if the name repeats it returns 1
			{flag=1;
			 p=p->next;
			 break;
			}
		 else
			{
			 p=p->next;
			}
		}
	}
 return flag;
	 
}

void removes()  //remove function
{
 int people, index,i, flag=0;
 NODE *p, *q;
 printf("How many people are in the reservation you would like to delete?\n");
 scanf("%d", &people);
 if(people==1 || people==2)
         index=0;
 else if(people==3 || people==4)
         index=1;
 else if(people==6 || people==6)
         index=2;
 else
         index=3;
for(i=0; i<=index; i++)
 {p=x[i].head;
  q=x[i].head;
  while(p!=NULL)
        {q=p;
	 if(p==x[i].head && p->group<=people) //case for if we are deleting the head
		{printf("%ss reservation has been deleted\n", p->name);
                 x[i].head=p->next;
                 free(p);
		 flag=1;
		 return;
                }
	 else 
		{p=p->next;
		 if(p->next!=NULL && p->group<=people) //case for if we are deleting the middle
			{printf("%ss reservation has been deleted\n", p->name);
	 		 q->next=p->next;
			 free(p);
			 flag=1;
			 return;
			}
	 	 else if(p->next==NULL && p->group<=people) //case for if we are deleting the last node
			{printf("%ss reservation has been deleted\n", p->name);
			 q->next=NULL;
			 x[i].tail=q;
			 free(p);
			 flag=1;
			 return;
			}
      		}
	 }
 }
 if(flag==0) //case for if the list is empty
         {printf("The list is empty. There is no one to delete\n");
          return;
         }
 return;
}

void listing() //listing function
{NODE *p;
 int i;
 for(i=0;i<4;i++)
	{p=x[i].head;
 	 while(p!=NULL) //if not empty, it prints all elements of the node
		{printf("%s - party of %d\n", p->name, p->group);
		 p=p->next;
		}
	}
 return;
}

void sizee() //search entry function
{NODE *p;
 int gsize, index, i, flag=0;
 printf("Enter the size of a group\n");
 scanf("%d", &gsize);
 if(gsize==1 || gsize==2)
          index=0;
 else if(gsize==3 || gsize==4)
          index=1;
 else if(gsize==6 || gsize==6)
          index=2;
 else
          index=3;
 for(i=0; i<=index; i++)
 {p=x[i].head;
 while(p!=NULL)
	{printf("%s - party of %d\n", p->name, p->group);
	 p=p->next;
	 flag=1;
	}
 }
 if(flag==0)
	printf("There are no reservations with that group size");
 return;
}

void backwards_list(NODE *p)
{
if(p==NULL)
	return;
if(p->next==NULL)
	{printf("%s - party of %d\n", p->name, p->group);
 	}
else 
	{backwards_list(p->next);
	 printf("%s - party of %d\n", p->name, p->group);
	}
 return;
}

void backwards_name(char *q)
{
 if(*(q+1)=='\0')
	{printf("%c", *q);}
 else
	{backwards_name(q+1);
 	 printf("%c", *q);

	}	
 return;
}

void clear(NODE *p) //clear function
{
 if(p==NULL)
	return;
 if(p->next==NULL)
	free(p);
 else
 	free(p);
	clear(p->next);
 return;
}

