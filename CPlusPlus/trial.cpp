vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;

    if (!root)
	return ret;
    
    queue<vector<int>> q;
    q.push(root->val);
    int currElemInQ = 1;

    while (!q.empty()) {
        
        TreeNode* curr = q.front();
        q.pop(); 
	currElemInQ--;
	
        if (curr && curr->left) {
	   q.push_back(curr->left->val);
        }
	if (curr && curr->right) {
	   q.push_back(curr->right->val);
        }

        if (currElemInQ == 0) {
        }
    }	     
}
