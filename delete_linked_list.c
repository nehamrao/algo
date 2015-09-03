

//Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};

/*
 * Method1: Keep track of the next pointer
 * of the next to next node in the ll in order
 * to set the last but one node to NULL to 
 * terminate linked list
 */ 
void deleteNode(struct ListNode* node) {
    struct ListNode* current = node;
    
    if (current == NULL) return;
    while (current->next != NULL && current->next->next != NULL) {
        current->val = current->next->val;
        current = current->next;
    }
    current->val = current->next->val;
    current->next = NULL;
}

/*
 * Method2: Keep track of the current & previous node
 * When the last node is reached, the previous nodes'
 * next pointer must be set to NULL to terminate the ll.
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* current = node;
    struct ListNode* previous = NULL;
    
    if (current == NULL) return;
    while (current->next != NULL) {
        current->val = current->next->val;
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
}
