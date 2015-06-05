#include <stdio.h>
#include <stdlib.h>

struct node {
    int    data;
    struct node *p_node;
};

void create_node(struct node *p_head, int data_a) {
     
    /* Allocate memory for the linked list*/
    p_head = malloc(sizeof(struct node));

    /* Add first node of linked list*/
    p_head->data = data_a;
    p_head->p_node = NULL;

    /* Check the values of the data*/
    printf("The data in first node is %d\n", p_head->data);
    free(p_head);
}

/*
 * Invokes create_node for each
 * node creation required to 
 * form the linked list
 */
void add_node(int num) {
    printf("CREATING a %d node linked list\n", num);
    create_node(NULL,12);
    
    struct node *p_first;
    create_node(p_first, 13);

    struct node *p_second;
    create_node(p_second, 78);
}

int main (void) {
    add_node(3); 
    return 0;
}
