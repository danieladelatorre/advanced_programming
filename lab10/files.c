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


void read_file(char *filename, int key) //read function
{FILE *fp;
 NODE *p;
 char username[20];
 int group;
 char line[200];
 char *q;
 
 fp = fopen(filename, "r");

 if(fp==NULL)
	 return;
 fseek(fp, 35, SEEK_SET); // skips the header
 while(fgets(line, 200, fp)!=NULL)
	{q=line;
	 while(*q!='\n')
		{*q^=key;
		 q++;
		}
	sscanf(line, "%s\t%d", username, &group);
	schedule(username, group);
	}
 fclose(fp);
return;
}


void save_file(char *filename, int key) // save function
{FILE *fp;
 NODE *p;
 int i;
 char line[200];
 char *q;
 

 fp=fopen(filename, "w");
 
 if(fp==NULL)
 {printf("Sorry buddy there is no file\n");
  return;
 }

 fprintf(fp, "NAME\tGROUP SIZE\n------------------\n"); //prints header to the text file
 for(i=0;i<4;i++)
 {p=x[i].head;
 while(p!=NULL)
 {sprintf(line, "%s\t%d\n", p->name, p->group);
  q=line;
  while(*q!='\0')
	{*q^=key;
	 q++;
	}
  fprintf(fp, "%s\n", line);
  p=p->next;
 }
}
 fclose(fp);
 return; 
}

void *autosave(void *arg)
{FILE *fp;
 NODE *p;
 int i;
 char *filename=(char *)arg;
 while(1)
	{sleep(15);
	 pthread_mutex_lock(&lock);
	 fp=fopen(filename, "wb");
	 for(i=0;i<4;i++)
	 	{p=x[i].head;
		 while(p!=NULL)
			{fwrite(p, sizeof(NODE), 1, fp);	 
			 p=p->next;
			}
		}
	 fclose(fp);
	 pthread_mutex_unlock(&lock);
	}
 return NULL;
}

void read_autosave(void *filename)
{FILE *fp;
 NODE temp;
 pthread_mutex_lock(&lock);
 fp=fopen(filename, "rb");
 if(fp==NULL)
	return;
 while(fread(&temp, sizeof(NODE), 1, fp)>0)
	{printf("%s\t%d\n", temp.name, temp.group);}
 fclose(fp);
 pthread_mutex_unlock(&lock);
 return;
}

