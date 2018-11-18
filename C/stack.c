#include<stdio.h>
#include<stdlib.h>

//Global linked list node defn
struct node {
    int data;
    struct node * next;
}*head;

//Pop function pops out last in data
int pop (){
    if(head) {
        int ret = head->data;
        struct node* tmp= head->next;
        free(head);
        head = tmp;  
        return ret;
    } else {
       printf("Popping Empty Stack, Beware!\n");
    }
}

//Push function pushes data to stack by adding a new ll node
void push(int data) {
    if (!head) {
       head = (struct node*) malloc(sizeof(struct node));
       head->data = data;
       head->next = NULL;
       return;
    }
    struct node *tmp = head;
    head = (struct node*) malloc(sizeof(struct node));

    head->data = data;
    head->next = tmp;
} 

int main (void){
   struct node *tmp = NULL; 
   int i;
   
   for (i = 0; i < 5; i++)
       push(i);
   
   printf("\n----- STACK PUSH -----\n");
   tmp = head;
   while (tmp) {
       printf("Pushed Data [%d]\n",tmp->data);
       tmp = tmp->next;
   }printf("\n----- STACK POP -----\n");
   
   while (head){
      printf("Popped Data [%d]\n",pop());
   }
   return 0;
}

