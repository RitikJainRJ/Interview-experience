int printLeaves(TreeNode *root, unordered_map<int, multiset<int>> &um){
    if(!root)   return 0;
    else{
        int left = printLeaves(root->left, um);
        int right = printLeaves(root->right, um);

        um[1 + max(left, right)].insert(root->val);
        return 1 + max(left, right);
    }
}

