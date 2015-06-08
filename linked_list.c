#include <stdio.h>
#include <stdlib.h>

struct node {
    int    data;
    struct node *next;
};

struct node* create_node(struct node* head, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;

    head = new_node;
    return head;
}

/*
 * Invokes create_node for each
 * node creation required to 
 * form the linked list
 */
struct node* add_node(int num) {
    printf("CREATING a %d node linked list\n", num);
    struct node* head;

    int i;
    for (i = 0; i < num; i++) {
	head = create_node(head, i);
    }
    
    return head;
}

void print_list(struct node* head) {
    struct node* itr = head;
    while (itr != NULL) {
	printf("%d\n", itr->data);
 	itr = itr->next;
    }
}

int main (void) {
    struct node* head = add_node(33);
    print_list(head);
    return 0;
}
