#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};

struct node* create_node(struct node* head,int data) {
    struct node* temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
   
    head = temp;
    return head;
}

struct node * linked_list_create(int n)
{
   struct node *head = NULL;
   int i = 0;
   for (; i < n; i++) {
       head = create_node(head,i);
   }   
   return head;
}

void linked_list_delete(struct node **head)
{
     struct node *current = *head;
     struct node *next;

     while(current != NULL) {
          next = current->link;
          free(current);
          current = next;
     }
     *head = NULL;
}

int main (void) {
    struct node *head;
    head = linked_list_create(3); 
    linked_list_delete(&head);
    return 0;
}
