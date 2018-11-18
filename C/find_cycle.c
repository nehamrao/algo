struct ListNode {
    int val;
    struct ListNode *next;
}

/*
 * This is an O(n^2) solution to determine if a 
 * linked list has a cycle/loop in it. checkCycle
 * function is used to check if the current head
 * is equal to any of the previos next pointers.
 * If yes, then we have a loop. We use the length
 * variable to differentiate a list w/o a loop vs 
 * one with the loop.
 */
bool checkCycle(struct ListNode *current, struct ListNode *actual, int len) {
   int i = 0;
   while (current && actual && i != len) {
       if (current == actual)
           return true;
       actual = actual->next; 
       i++;
   }
   return false;
} 
 
bool hasCycle(struct ListNode *head) {
    
    if (!head || !head->next)
        return false;
        
    struct ListNode* tmp = head; /* Save head */
    head = head->next; /* Start from head's next */
    
    bool ret;
    int len = 1; 
    
    while (head) {
        ret = checkCycle(head, tmp, len);
        if (ret == true)
            return true;
        head = head->next;
        len++;
    }
    return false;
}
