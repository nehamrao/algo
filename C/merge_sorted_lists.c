/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Recursive solution to merge two sorted lists. First, check the
 * base conditions. After that, if value in node of one list is 
 * lesser than/equal to value in node of other list, update the
 * the result list 'n' as that. n's next will be a recursive
 * computation of the updated list and its counterpart.
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* n = NULL;
    
    if (!l1 && !l2) return NULL;
    if (l1 && !l2) return l1;
    if (l2 && !l1) return l2;
    
    if (l1->val <= l2->val) {
        n = l1;
        n->next = mergeTwoLists(l1->next, l2);
    } else {
        n = l2;
        n->next = mergeTwoLists(l1, l2->next);
    }
    return n;
}
