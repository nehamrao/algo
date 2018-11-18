/*
 * Floyd's Cycle-Finding Algorithm: Completely non-intuitive
 * but very sweet way of determining if a linked list has a
 * cycle/loop. Keep track of two pointers: "slow" keeps track
 * of the next pointers and "fast" keeps track of next->next
 * pointers. If they are equal, there is a loop. 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
