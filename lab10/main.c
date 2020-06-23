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

struct list x[4]={{NULL,NULL},{NULL,NULL},{NULL,NULL},{NULL,NULL}};
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int main(int argc, char*argv[]) //main function
{int option, groupies, new, index, i;
 char username[20];
 char *q;
 NODE *p;
 if(argc<3)
	{printf("Error\n");
	 return 0;
	}
 pthread_t thread;
 pthread_create(&thread, NULL, &autosave, (void*)argv[2]);
 read_file(argv[1], atoi(argv[3]));
 while(1)
  {printf("Press:\n 1 to schedule a reservation\n 2 to cancel a reservation\n 3 to list the reservations\n 4 to see entries\n 5 to list the entries backwards\n 6 to list the names backwards\n 7 to read the autosaved binary file\n 0 to quit\n");
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
   case 7:
    {
     read_autosave(argv[2]);
     break;
    }
   case 0:
    {
     save_file(argv[1], atoi(argv[3]));
     pthread_mutex_lock(&lock);
     pthread_cancel(thread);
     pthread_mutex_unlock(&lock);
     for(i=0; i<4; i++)
	{p=x[i].head;
     	 clear(p);
	}
     return 0;
     break;}
   default:
     {printf("The option you entered is invalid");
      break;}
    }
  }

}
