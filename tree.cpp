#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

class TreeNode {
    public:
	TreeNode (int v, TreeNode* l, TreeNode* r, bool visited);
	int val;
	TreeNode* left;
	TreeNode* right;
	bool visited;
};

TreeNode::TreeNode (int v, TreeNode* l, TreeNode* r, bool visit)
{
    val = v;
    left = l;
    right = r;
    visited = visit;
}

void printPostOrder (TreeNode* root)
{
    if (root->left) printPostOrder(root->left);
    if (root->right) printPostOrder(root->right);
    cout << root->val << " ";
}

void printPreOrder (TreeNode* root)
{
    cout << root->val << " ";
    if (root->left) printPreOrder(root->left);
    if (root->right) printPreOrder(root->right);	
}

void printInOrder (TreeNode* root)
{
    if (root->left) printInOrder(root->left);
    cout << root->val << " ";
    if (root->right) printInOrder(root->right);
}

void printLevelOrder (TreeNode* root) 
{
    std::queue<TreeNode*> q;
    q.push(root);    

    while (!q.empty()) {
        TreeNode* curr = q.front();
	if (curr && curr->left)
	    q.push (curr->left);
	if (curr && curr->right)
	    q.push (curr->right);
        cout << curr->val << " ";
	q.pop();
    }
}

void printLevelOrderReverse (TreeNode* root)
{
    std::stack<TreeNode*> s;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
	if (curr && curr->right)
	    q.push(curr->right);
        if (curr && curr->left)
	    q.push(curr->left);
        s.push(curr);
	q.pop();
    }

    while (!s.empty()) {
        TreeNode* node = s.top();
        cout << node->val << " ";
        s.pop(); 
    }
}

bool areChildrenVisited(TreeNode* node) {
    bool visited = true;
    if (node->left && !node->left->visited) visited = false;
    if (node->right && !node->right->visited) visited = false;
    return visited;
}

void printPaths (TreeNode* root)
{
    vector<TreeNode*> v;
    
    v.push_back(root);
    while (!v.empty()) {
        TreeNode* curr = v.back();

        // Leaf node
        if (!curr->left && !curr->right) {
	   curr->visited = true;

           for (int i = 0; i < v.size(); i++) {
               cout << v.at(i)->val << " ";
           } cout << "\n";

           v.pop_back();
        }

        // Both children visited
        else if (areChildrenVisited(curr)) {
	   curr->visited = true; 
           v.pop_back();
	}
	// Left child not visited
        else if (curr->left && !curr->left->visited) {
           v.push_back(curr->left);
	}
        // Right child not visited
        else if (curr->right && !curr->right->visited) {
           v.push_back(curr->right);
	}
    }
}

void pathSum(TreeNode* root, int sum) {
        vector<TreeNode*> v;
          
        // Push root to vector
        v.push_back(root);
        while (!v.empty()) {
            TreeNode* curr = v.back();
            // Leaf node
            if (!curr->left && !curr->right) {
                curr->visited = true;
                
                int path_sum = 0;
                for (int i = 0; i < v.size(); i++) {
                    path_sum += v.at(i)->val;
                }
                
                // Compare path sum to input sum
                if (path_sum == sum) {
                    for (int j = 0; j < v.size(); j++) {
               	        cout << v.at(j)->val << " ";
                    } cout << "\n";     
                }
                v.pop_back();
            }
            
            // Left child not visited
            else if (curr->left && !curr->left->visited) {
                v.push_back(curr->left);
            }
            
            // Right child not visited
            else if (curr->right && !curr->right->visited) {
                v.push_back(curr->right);
            }
            
            // Both childern visited
            else if (areChildrenVisited(curr)) {
                curr->visited = true;
                v.pop_back();
            }
        }
}

int getAllPathSum (TreeNode* root)
{
    vector<TreeNode*> v;
    vector<int> sum_vector;
    int ret;

    v.push_back(root);
    while (!v.empty()) {
        TreeNode* curr = v.back();
        
        // Leaf Node
        if (!curr->left && !curr->right) {
            curr->visited = true;
            
            int sum = 0;
            // Compute sum
            for (int i = 0; i < v.size(); i++) {
                sum += pow(10, (v.size()-(i+1)))*(v.at(i)->val);
            }
            sum_vector.push_back(sum); 
            cout << "Sum " << sum << "\n";
            v.pop_back();
        }

        // Left child not visited
        else if (curr->left && !curr->left->visited) {
            v.push_back(curr->left);
        }
        
        // Right child not visited
        else if (curr->right && !curr->right->visited) {
            v.push_back(curr->right);
        }

        else if (areChildrenVisited(curr)) {
            curr->visited = true;
            v.pop_back(); 
        }
    }
    ret = 0;
    for (int i = 0; i < sum_vector.size(); i++) {
        ret += sum_vector.at(i);
    }
    return ret;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<TreeNode*> v;
    vector<string> ret;
    TreeNode* prev = NULL;    
    
    if (!root) return ret;
 
    v.push_back(root);
    while (!v.empty()) {
        TreeNode* curr = v.back();

        // Leaf node
        if (!curr->left && !curr->right) {
	    prev = curr;
            // Add path to return vector
            string path;
            for (int i = 0; i < v.size(); i++) {
                path += "->";
                path += to_string(v.at(i)->val);
            }
            ret.push_back(path);
            v.pop_back();
        }

        // Both children visited
        else if (areChildrenVisited(prev, curr)) {
            prev = curr;
            v.pop_back();
        }

       // Left child not visited
       else if (curr->left && (prev != curr->left)) {
           v.push_back(curr->left);
       }

       // Right child not visited
       else if (curr->right && (prev != curr->right)) {
           v.push_back(curr->right);
       }
    }        
}

vector<int> binaryTreeInOrderTraversal(TreeNode* root) {
    vector<TreeNode*> v;
    vector<int> ret;
    TreeNode* prev = NULL;    

    v.push_back(root);
    while (!v.empty()) {
        TreeNode* curr = v.back();

        // Leaf Node
        if (!curr->left && !curr->right) {
            prev = curr;
            ret.push_back(curr->val);
            v.pop_back();
        }
       
        // Left child not visited
        else if (curr->left && prev != curr->left) {
            v.push_back(curr->left);
        }

        // Right child not visited
        else if (curr->right && prev != curr->right) {
            ret.push_back(curr->val);
	    v.push_back(curr->right);
        }

       // Both children visited
       else if (areChildrenVisited(prev, curr)) {
           prev = curr; 
           v.pop_back(curr);
       }
    }
}

void flatten (TreeNode* root) {
    TreeNode* curr = root;
    TreeNode* old_right = NULL;

    while (curr) {
        
	// Both left and right children exist
	if (curr->right && curr->left) {
            old_right = curr->right;    
            curr->right = curr->left;
	    // Iterate over the modified tree
	    TreeNode* temp = root;
	    while (temp) {
		// Rightmost child
                if (!temp->right) {
                    temp->right = old_right;
                }
		temp = temp->right;
            }		
        }
	curr = curr->right;
    }

    curr = root;
    while (curr) {
        if (curr->right)
	    cout << curr->right->val << " ";
        curr = curr->right;
    }
}
bool areChildrenVisited (TreeNode* curr, TreeNode* prev) {
    // Left child not visited
    if (curr->left && prev != curr->left)
	return false;

    // Right child not visited
    if (curr->right && prev != curr->right)
	return fasle;
    
    // Both children not visited
    if (curr->left && prev != curr->left)
	return false;
    return true;
}


// Find kth smallest element of BST
int findKthSmallest (TreeNode* root) {
    vector<TreeNode*> v;
    TreeNode* prev = NULL;
    vector<int> ret;

    v.push_back(root);
    while (!v.empty()) {
        TreeNode* curr = v.back();

        // Leaf node
        if (!curr->left && !curr->right) {
            prev = curr;
            ret.push_back(curr);
            v.pop_back();
        }

        // Both children are visited
	if (areChildrenVisited(curr, prev)) {
            prev = curr;
	    v.pop_back();
        }

        // Left child not visited
	if (curr->left && prev != curr->left) {
            v.push_back(curr);
        }

        // Right child not visited
        if (curr->right && prev != curr->right) {
            v.push_back(curr);
            ret.push_back(curr);
        }
    }
}

int main () 
{       	
	
	TreeNode n7 (7, NULL, NULL, false);
	TreeNode n6 (6, NULL, NULL, false);
	TreeNode n5 (5, NULL, NULL, false);
	TreeNode n4 (4, NULL, NULL, false);
	
	TreeNode n3 (3, &n6, &n7, false);
	TreeNode n2 (2, &n4, &n5, false);
	TreeNode n1 (1, &n2, &n3, false);
  
/*	printInOrder (&n1); cout << "\n";
	printPreOrder (&n1); cout << "\n";
	printPostOrder (&n1); cout << "\n";
        printLevelOrder (&n1); cout << "\n";	
        printLevelOrderReverse (&n1); cout << "\n";        
	printPaths (&n1); cout << "\n";
        pathSum (&n1, 11); cout << "\n";
        int sum = getAllPathSum (&n1);
        cout << "Sum: " << sum << "\n";
*/      flatten(&n1);
        return 0;
} 
