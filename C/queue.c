#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node* next;
}*head;

//Dequeue function to return first in data [FIFO]
int dequeue () {
   if (head) {
       struct node* tmp = head->next;
       int ret = head->data;
       free(head);
       head = head->next;
       return ret;    
   } 
   assert(0);//If ever we reach this erronous point
}

//Function to find the previous node given current node ptr
struct node* find_prev (struct node* tmp) {
    struct node *prev = NULL;

    while (tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    return prev;
}

//Queue function to add nodes to a ll such that the head is retained
void queue (int data) {
    if (!head) {
        head = (struct node*) malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return;
    }
    
    struct node* tmp = (struct node*) malloc(sizeof(struct node));
    struct node* prev = find_prev(head);
    prev->next = tmp;
    tmp->data = data;
    tmp->next = NULL;    
} 


int main (void)
{
    int i;
    for (i = 0; i < 5; i++) {
       queue(i);
    }
    
    printf("\n\n -----  Queue Data  -----\n"); 
    struct node* tmp = head;
    while(tmp) {
        printf("Queued data [%d]\n", tmp->data);
        tmp = tmp->next;
    }    
 
    printf("\n\n -----  Dequeue Data  -----\n"); 
    while(head){
        printf("Dequeued data [%d]\n", dequeue());
    }
    return 0;
}

