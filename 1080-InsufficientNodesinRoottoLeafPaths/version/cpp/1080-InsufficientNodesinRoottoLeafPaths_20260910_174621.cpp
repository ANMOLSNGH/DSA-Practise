// Last updated: 9/10/2026, 5:46:21 PM
1class Solution {
2public:
3    TreeNode* sufficientSubset(TreeNode* root, int limit) {
4        if (!root) return nullptr;
5        
6        if (!root->left && !root->right) {
7            if (root->val < limit) {
8                return nullptr; 
9            }
10            return root; 
11        }
12        root->left = sufficientSubset(root->left, limit - root->val);
13        root->right = sufficientSubset(root->right, limit - root->val);
14     
15        if (!root->left && !root->right) {
16            return nullptr;
17        }
18        
19        return root;
20    }
21};