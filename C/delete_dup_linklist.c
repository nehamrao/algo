/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Given a sorted linked list, delete the duplicate
 * nodes from it. Return the head pointer.
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    
   //Example: 1->1->2->2
   while (current && current->next && current->next->next) {
        /*
         * If two adjacent nodes have the same value
         * we need to save the next pointers before 
         * and after the node we will delete. Free the 
         * duplicate node & assign the previous nodes
         * next to the saved next node.
         */ 
        if (current->val == current->next->val) {
            struct ListNode* tmp1 = current->next;
            struct ListNode* tmp2 = current->next->next;
            free(tmp1);
            current->next = tmp2; 
        } else {
            //If adjacent nodes do not have same values, increment current
            current = current->next;
        }
    }
    //Either !current or !current->next or !current->next->next. Handles
    //the case when only two nodes are left to be checked.
    if (current && current->next && (current->val == current->next->val)) {
         struct ListNode* tmp3 = current->next;
         free(tmp3);
         current->next = NULL;
    }
    return head;
}
