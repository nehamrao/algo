/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Reverse a given linked list.
 * We need to keep track of the next pointers
 * as well as the new heads that are created. First,
 * break the list such that the first node becomes 
 * a new list. Reference to the old list is saved 
 * in tmp. Now using tmp, save it's next in tmp2.
 * Assign tmp->next to the original head by which
 * we append the new node to  the head of the first.
 * Reassign head as well to reflect the updates list.
 */
struct ListNode* reverseList(struct ListNode* head) {
    //Handle empty linked list
    if (!head)
       return;
    //Handle single node list 
    if (head->next == NULL)
        return head;
    //tmp keeps track of the next pointers from the list
    //tmp2 keeps track of the new head node created  
    struct ListNode* tmp = head;
    struct ListNode* tmp2;
    tmp = tmp->next;
    head->next = NULL;
  
    while (tmp) {
        tmp2= tmp;
        tmp = tmp->next;
        tmp2->next = head;
        head = tmp2;
    }
    
    return tmp2;
}
