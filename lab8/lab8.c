/* Daniela De La Torre
   COEN11
   February 18 2019
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
struct list
	{NODE *head;
	 NODE *tail;
	};
struct list x[4]={{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL}};

int check_duplicates(char *username); //prototype for the check_duplicates function
int main(int argc, char *argv[]); //prototype for main function

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
	{clear(p->next);
	free(p);
	}
 return;
}

void read_file(char *filename) //read function
{FILE *fp;
 char username[20];
 int group;
 
 fp = fopen(filename, "r");

 if(fp==NULL)
	 return;
 fseek(fp, 35, SEEK_SET); // skips the header
 while(fscanf(fp, "%s%d", username, &group)==2) //scans the names and groups in the text file and puts it into nodes
	schedule(username, group);
 fclose(fp);
return;
}


void save_file(char *filename) // save function
{FILE *fp;
 NODE *p;
 int i;

 fp=fopen(filename, "w");
 
 if(fp==NULL)
 {printf("Sorry buddy there is no file\n");
  return;
 }

 fprintf(fp, "NAME\tGROUP SIZE\n------------------\n"); //prints header to the text file
 for(i=0;i<4;i++)
 {p=x[i].head;
  while(p!=NULL)
	{fprintf(fp, "%s\t\t%d\n", p->name, p->group); //prints the names and group sizes in the nodes
	 p=p->next;
	}
 }
 fclose(fp);
 return; 
}


int main(int argc, char*argv[]) //main function
{int option, groupies, new, index, i;
 char username[20];
 char *q;
 NODE *p;
 if(argc==1)
	{printf("The name of the file is missing");
	 return 1;
	}
 read_file(argv[1]);
 while(1)
  {printf("Press:\n 1 to schedule a reservation\n 2 to cancel a reservation\n 3 to list the reservations\n 4 to see entries\n 5 to list the entries backwards\n 6 to list the names backwards\n 0 to quit\n");
   scanf("%d", &option);
   switch(option)
   {case 1:
      {printf("Please enter your name\n");
   scanf("%s", username);
   new = check_duplicates(username);
   while(1)
   {if(new==1) //if name repeats they must enter another name
          {printf("There is already a reservation with this name. Pick another name\n");
           scanf("%s", username);
           new = check_duplicates(username); 
          }
  
   if(new==0)
          {
           printf("Please enter your group size\n");
           scanf("%d", &groupies);
	   break;
          }
   }
   printf("Hello %s, your reservation has been created \n", username);
       schedule(username, groupies);
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
   case 5:
       {for(i=3;i>=0;i--)
		{p=x[i].head;	 
		 backwards_list(p);
		}
	break;
       }
   case 6:
       {for(i=0; i<4; i++)
		{p=x[i].head;
		 while(p!=NULL)
			{q=p->name;
		 	 backwards_name(q);
			 printf("\n");
			 p=p->next;
			}
		}
	break;
       }
   case 0:
    {save_file(argv[1]);
     for(i=0; i<4; i++)
	{p=x[i].head;
     	 clear(p);
	}
     return 1;
      break;}
   default:
     {printf("The option you entered is invalid");
      break;}
    }
  }

}
