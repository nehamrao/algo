/*
 * Linked list (insert, find, delete funtions)
 */
#include <iostream>

using namespace std;

template<typename T>
class LinkedList
{
  public:
    T *ghead;
    // Inserts node to the end of the list an returns root
    void insertEndOfLL (int val)
    {    
        if (ghead == NULL) {
            ghead = new T;
            ghead->val = val;
            ghead->next = NULL;
            return;
        }
        T *temp = ghead;
        while (temp) {
            if (temp->next == NULL) {
                T *node = new T;
                node->val = val;
                node->next = NULL;
                temp->next = node;
                return;
            }
            temp = temp->next;
        }
    }
    
    void insertBeginLL (int val) 
    {
        if (ghead == NULL) {
            ghead = new T;
            ghead->val = val;
            ghead->next = NULL;
            return;
        }
        
        T *temp = new T;
        temp->val = val;
        temp->next = ghead;
        ghead = temp;
    }
    
    // Finds node pointer containing the given val
    T *findInLL (int val) {
        T *temp = ghead;
        while (temp) {
            if (temp->val == val) {
                return temp;
            } else {
                temp = temp->next;
                if (temp == NULL) {
                    // Last node, no match
                    //cout<<"No node in  linkedlist with val " << val << "\n";
                    return NULL;
                }
            }
        }
    }

    // Finds the prev node, given a val 
    T * findPrevLL (int val) {
        T *temp = ghead;
        T *prev = ghead;
        while (temp) {
            if (temp->next == NULL) {
                if (temp->val == val) {
                    return prev;
                } else {
                    return NULL;
                }            
            } else if (temp->val == val) {
                return prev;
            } 
            prev = temp;
            temp = temp->next;
        }
        return prev;
    }
    
    // Deletes node in list
    void deleteInLL (int val)
    {
        T *prev = findPrevLL(val);
        T *curr = findInLL(val);
        
        if (!prev && !curr) {
            cout<<"Delete failed, node with val " << val << " not present in linked list\n";
            return;
        }
        
        // Deleting first element 
        if (prev == curr) {
            
            T *temp = curr->next;
            delete(curr);
            ghead = temp;
            return;
        }
        
        if (prev) {
            prev->next = curr->next;
            delete(curr);
        }
    }
    
    void printList () {
        T *temp = ghead;
        while (temp) {
           if (temp->next == NULL) {
                 cout<<temp->val<<'\n';
            } else {
                   cout<<temp->val<<" --> ";
            }
           temp = temp->next;
        }
    }
   
};


class ListNode {
  public: 

    ListNode *next;
    int val;
};


int main() {
    LinkedList<ListNode> *list = new LinkedList<ListNode>;
    
    list->insertEndOfLL(1900);
    list->insertEndOfLL(367);
    list->insertEndOfLL(2);
    list->insertEndOfLL(44);
    list->insertBeginLL(33);
    list->printList();
    
    ListNode *node = list->findInLL(367);
    list->deleteInLL(22);
    list->findPrevLL(22);
    list->printList();

    return 0;
}
