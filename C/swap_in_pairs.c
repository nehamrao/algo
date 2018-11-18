/*
 *  Given a linked list, swap every two adjacent nodes and return its head.
 *  For example, Given 1->2->3->4, you should return the list as 2->1->4->3. 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
    if (!head || !head->next) 
        return head;
        
    struct ListNode* second = head->next;
    struct ListNode* third = second->next;
   
    second->next = head;
    head->next = swapPairs(third);
    
    return second;
}
