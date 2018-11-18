#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/*
 * Implementation of a binary tree
 * - Insert, Delete, Find
 * - Pre-order, post-order, in-order
 */

// Test class
class Person {
  public:
   int age;
   string name;
   void printPerson () {
       cout << "Name: " << name << " Age: " << age << "\n";
   }
       
   bool operator== (Person data) {
       if (this->age == data.age && this->name == data.name)
            return true;
       return false;
   } 
};


// Yes i had like this 
template <typename T>
class TreeNode {
  public:
    TreeNode<T>* left; // I was missing this!!!
    TreeNode<T>* right;
    T data;
};


template <typename T>
class BinaryTree {
  public:
    TreeNode<T> *root;
    
    BinaryTree() {
        root = NULL;
    }
    
    TreeNode<T> *makeNode (TreeNode<T> *node, T data) 
    {
        if (!node) {
            node = new TreeNode<T>;
            node->left = NULL;
            node->right = NULL;
            node->data = data;
            return node;
        }
    }
    
    void makeTree (vector<T> v) 
    {
        queue<TreeNode<T> *> q;
        
        // Make root
        root = makeNode(NULL, v[0]);
        q.push(root);
        
        // Iterate over the array list
        int i = 1;
        while (i != v.size()) {
            // Get parent
            TreeNode<T> *parent = q.front();
            q.pop();
            
            // Create the left and right children
            TreeNode<T> *lChild = NULL;
            TreeNode<T> *rChild = NULL;
            
            lChild = makeNode(parent->left, v[i]);
            q.push(lChild);
            i++;
            
            // Since we are incrementing i, must ensure we don't overrun v's index
            if (i != v.size()) {
                rChild= makeNode(parent->right, v[i]);
                q.push(rChild);
                i++;
            }
            
            parent->left = lChild;
            parent->right = rChild;
        }
        
    }
    
    void printTree () 
    {
        cout << "\nPRINTING *** PRE-ORDER ***\n";
        printTreePreOrder (root);
        cout << "\nPRINTING *** POST-ORDER ***\n";
        printTreePostOrder (root);
        cout << "\nPRINTING *** IN-ORDER ***\n";
        printTreeInOrder (root);
        cout << "\nPRINTING *** LEVEL-ORDER ***\n";
        printTreeLevelOrder (root);
    }
    
    // LOOK AT THIS FUNCTION
    // IT KNOWS THAT root IS OF TYPE TREENODE<T> i.e. root->data is of type T
    // You can't have a generic print method being invoked here that works for all datatypes
    void printTreePreOrder (TreeNode<T> *root)
    {
        if (!root) {
            return;
        }
        
        root->data.printPerson();
        printTreePreOrder (root->left);
        printTreePreOrder (root->right);
    }
    
    void printTreePostOrder (TreeNode<T> *root)
    {
        if (!root) {
            return;
        }
        
        printTreePostOrder (root->left);
        printTreePostOrder (root->right);
        root->data.printPerson();
    }
    
    void printTreeInOrder (TreeNode<T> *root) 
    {
        if (!root) {
            return;
        }
        
        printTreeInOrder (root->left);
        root->data.printPerson();
        printTreeInOrder (root->right);
    }
     
    void printTreeLevelOrder (TreeNode<T> *root) 
    {
        if (!root) {
            return;
        }
        
        queue<TreeNode<T> *> q;
        int currLevelCnt = 1;
        
        // Handle root
        q.push(root);

        
        while (!q.empty()) {
            TreeNode<T> *curr = q.front();
            curr->data.printPerson();
            q.pop();
            currLevelCnt--;
            
            
            if (curr->left) 
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            
            if (currLevelCnt == 0) {
                currLevelCnt = q.size();
            }
        }
        
    }
    
    TreeNode<T>* findNode (T data) {
        
        return findNodeHelper (root, data);
        
    }
    
    TreeNode<T>* getAncestor (TreeNode<T> *p, TreeNode<T> *q) {
        return getAncestorHelper (p, q, root);
    }
  public:
    TreeNode<T> *getAncestorHelper (TreeNode<T> *p, TreeNode<T> *q, TreeNode<T> *root) {
        if (!root)
            return NULL;
        
        if (root->data == p->data || root->data == q->data)
            return root;
        
        TreeNode<T> *left = getAncestorHelper(p, q, root->left);
        TreeNode<T> *right = getAncestorHelper(p, q, root->right);
        
        if (left == NULL && right == NULL)
            return NULL;
        else if (left && right)
            return root;
        
        return (!left && right ? right : left); 
    }
    
    TreeNode<T> *findNodeHelper(TreeNode<T> * curr, T data) {
        if (!curr)
            return NULL;
        
        if (curr->data == data)
            return curr;
        
        TreeNode<T> *left = findNodeHelper(curr->left, data);
        TreeNode<T> *right = findNodeHelper(curr->right, data);
        
        return (left != NULL ? left : right);
    }

};

int main() {
    
    // Test node add to tree
    Person p;
    p.age = 25;
    p.name = "Neha";
    
    Person q;
    q.age = 27;
    q.name = "Chinna";
    
    Person r;
    r.age = 28;
    r.name = "Golu";
    
    Person s;
    s.age = 29;
    s.name = "Gudda";
    
    Person t;
    t.age = 29;
    t.name = "Gumbal";
    
    vector<Person> v;
    v.push_back(p);
    v.push_back(q);
    v.push_back(r);
    v.push_back(s);
    v.push_back(t);
    
    BinaryTree<Person> *tree = new BinaryTree<Person>();
    tree->makeTree(v);
    tree->printTree();
    
    // Test find API
    cout << "\n";
    TreeNode<Person> *found = tree->findNode(s);
    if (found)
        found->data.printPerson();
    TreeNode<Person> *another = tree->findNode(q);
    
    // Test ancestor
    cout << "\n";
    TreeNode<Person> *anc = tree->getAncestor(found, another);
    anc->data.printPerson();
    return 0;
}