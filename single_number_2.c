#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int count;
    struct node *next;
};

/*
 * Search through the linked list to find if the data in 
 * any node matches the array element. If it does, update
 * the count. Return true if a match is found, else return 
 * false if none of the exisitng nodes have the same data.
 */
bool search_node(int data, struct node* head) {
    while (head && head->next != NULL) {    
        if (head->data == data) {
            head->count = head->count + 1;
            printf("Updating count for %d, new count is %d\n",head->data,head->count);
            return true;
        }
        head = head->next;
    }
    return false;
}

/*
 * Function to create a node of a linked list
 */
struct node * create_node (int data, struct node* next) {
    struct node * head = NULL;
    head = (struct node*) malloc(sizeof(struct node));
 
    head->data = data;
    head->count = 1;
    head->next = next;
    return head;
}

/*
 * Pass the head node as argument to find the node
 * which has count as 1 which gives the single number
 */
int find_single(struct node *head) {
    while (head && head->count != 1) {
        head = head->next;
    }
    return (head->data);
}

/*
 * Find the single number in an array where each digit appears
 * 3 times except this one digit.
 */
int singleNumberTwo(int *a, int n) {
    
    //Suppose array is empty
    if (n == 0)
        return 0;

    //Suppose there is no single number
    if (n%3 == 0)
        return 0;
    
    //STEP1: Create first node of linked list
    struct node *head = create_node(a[0],NULL);

    //STEP2: Now populate more nodes and update count
    int i = 1;
    bool res;
    for (;i < n; i ++) {
        printf("i is %d\n",i);
        res = search_node(a[i], head);
        //If res if false, a match isn't found in ll so add new node
        if (res == false) 
            head = create_node(a[i], head);
    }  
    struct node* temp = head;
    while (temp && temp->next != NULL) {
            printf("Data: %d, Count: %d\n",temp->data,temp->count);
            temp = temp->next;
    }
    int num = find_single(head);
    return num;
}

int main (void) {
    int a[7] = {2, 2, 3, 2, 17, 3 , 3};
    int res = singleNumberTwo(a,7);
    printf("The single number is %d\n", res);
}
