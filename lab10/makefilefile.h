#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
extern pthread_mutex_t lock; 
typedef struct node     //initializes the structure with name, group, and node
 { char name[20];
   int group;
   struct node *next;
 }NODE;
typedef struct list
        {NODE *head;
         NODE *tail;
         }LIST;
extern LIST x[4];
int check_duplicates(char *);
void schedule(char *, int);
void removes();
void listing();
void sizee();
void backwards_list(NODE *);
void backwards_name(char *);
void clear(NODE *);
void read_file(char *, int);
void save_file(char *, int);
void read_autosave(void *);
void *autosave(void *);
