#include <stdio.h>
#include <stdlib.h>

struct node {
    int    data;
    struct node *next;
};

struct node* create_node(struct node *p_head, int data_a) {
     
    /* Allocate memory for the linked list*/
    p_head = malloc(sizeof(struct node));

    /* Add first node of linked list*/
    p_head->data = data_a;
    p_head->next = NULL;

    /* Check the values of the data*/
    printf("The data in first node is %d\n", p_head->data);
    return p_head;
}

/*
 * Invokes create_node for each
 * node creation required to 
 * form the linked list
 */
struct node* add_node(int num) {
    printf("CREATING a %d node linked list\n", num);
    struct node* p_head = create_node(NULL,12);
    struct node* first_node = create_node(p_head, 13);
    struct node* second_node = create_node(first_node, 78);
    
    printf("Node1 [data]: %d, Node2 [data]: %d, Node3 [data]: %d\n", 
           second_node->data, first_node->data, p_head->data);   
    return second_node;
}

int main (void) {
    add_node(3);
    return 0;
}
