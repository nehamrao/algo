#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <typename T>
class Node{
  public:
    Node<T>* left;
    Node<T>* right;
    T data;
};

template <typename T>
class BinarySearchTree {
  public:
    Node<T>* root;
    
    BinarySearchTree() {
        root = NULL;
    }
    
    Node<T> *makeNode (T data) {
        Node<T> *curr = new Node<T>;
        curr->left = NULL;
        curr->right = NULL;
        curr->data = data;
        return curr;
    }
    
    void createBST (vector<T> v) {
        root =  makeBSTHelper (v, 0, v.size() - 1);
    }
    
    int getHeight () {
        return getHeightHelper(root);    
    }
    
    Node<T> *searchBST (T data) {
        return searchBSTHelper(root, data);    
    }
    
    void printTree () 
    {
        cout << "\nPRINTING *** IN-ORDER ***\n";
        printTreeInOrder (root);
    }
    
    void printTreeInOrder (Node<T> *root) 
    {
        if (!root) {
            return;
        }
        
        printTreeInOrder (root->left);
        root->data.printStudentInfo();
        printTreeInOrder (root->right);
    }
    
    Node<T>* getAncestor (Node<T>* p, Node<T>* q) {
        return getAncestorHelper (p, q, root);
    }
    
    bool isValidBST () {
        return isValidBSTHelper (root);
    }
  private:
    Node<T> *makeBSTHelper (vector<T> v, int start, int end) {
    
        if (v.size() == 0) {
            cout << "Please provide non-empty array list to construct BST\n";
            return NULL;
        }
        
        // Stop the recursion
        if (start > end)
            return NULL;
        
        int mid = start + (end - start)/2;
        
        // Make root
        Node<T> *curr = makeNode(v[mid]);

        // Make left subtree
        curr->left = makeBSTHelper(v, start, mid - 1);
        // Make right subtree
        curr->right = makeBSTHelper(v, mid + 1, end);
        
        return curr;
    }
    
   int getHeightHelper (Node<T> *curr) {
       if (!curr)
           return 0;
       
       return 1 + max(getHeightHelper(curr->left), getHeightHelper(curr->right));
   }
    
   Node<T> *searchBSTHelper (Node<T> *curr, T data) {
       if (!curr) {
           return NULL;
       }
       
       if (curr->data == data) {
           return curr;
       } else if (curr->data.id > data.id) {
           return searchBSTHelper(curr->left, data);
       } else if (curr->data.id < data.id) {
           return searchBSTHelper(curr->right, data);
       }
   }
    
   Node<T> *getAncestorHelper (Node<T>* p, Node<T>* q, Node<T> *root) {
       if (!root)
            return NULL;
       
       if (p->data.id > root->data.id && q->data.id > root->data.id) {
           return getAncestorHelper(p, q, root->right);
       } else if (p->data.id < root->data.id && q->data.id < root->data.id) {
           return getAncestorHelper(p, q, root->left);
       } else {
           return root;
       }
   }
    
   bool isValidBSTHelper (Node<T> *root) {
       if (!root)
           return true;
       
       if ((root->left && root->data <= root->left->data) || (root->right && root->data >= root->right->data))
           return false;
       return isValidBSTHelper (root->left) && isValidBSTHelper (root->right);
       
   }
}; 


class StudentInfo {
  public:
    bool operator== (StudentInfo a) {
        if (this->id == a.id && this->name == a.name)
            return true;
        return false;
    }
    
    bool operator<= (StudentInfo a) {
        if (a.id < this->id || a.id == this->id)
            return false;
        return true;
    }
    
    bool operator>= (StudentInfo a) {
        if (a.id > this->id || a.id == this->id)
            return false;
        return true;
    }
    
    void printStudentInfo () {
        cout << "Student id [" << id << "], Name[" << name << "]\n";     
    }
    
    int id;
    string name;
};

bool compareByLength (const StudentInfo &a, const StudentInfo &b)
{
      return a.id < b.id;
}

int main() {
    
    StudentInfo p;
    p.id = 1234;
    p.name = "Neha";
    
    StudentInfo q;
    q.id = 1235;
    q.name = "Chinna";
    
    StudentInfo r;
    r.id = 1245;
    r.name = "Golu";
    
    StudentInfo s;
    s.id = 1456;
    s.name = "Gudda";
    
    StudentInfo t;
    t.id = 1563;
    t.name = "Gumbal";
    
    vector<StudentInfo> v;
    v.push_back(p);
    v.push_back(q);
    v.push_back(r);
    v.push_back(s);
    v.push_back(t);
    
    sort(v.begin(), v.end(), compareByLength);

    BinarySearchTree<StudentInfo> *tree = new BinarySearchTree<StudentInfo>();
    tree->createBST(v);
    tree->printTree();
    cout << "Max depth of tree: " << tree->getHeight() << "\n";
    Node<StudentInfo> *found = tree->searchBST(p);
    if (found)
        found->data.printStudentInfo();
    
    
    // Test ancestor
    Node<StudentInfo> *a = tree->searchBST(s);
    Node<StudentInfo> *b = tree->searchBST(r);
    Node<StudentInfo> *anc = tree->getAncestor(a, b);
    anc->data.printStudentInfo();
    
    // Test isValidBST function
    bool isValid = tree->isValidBST ();
    
    if (isValid)
        cout << "Tree is valid\n";
    return 0;
}