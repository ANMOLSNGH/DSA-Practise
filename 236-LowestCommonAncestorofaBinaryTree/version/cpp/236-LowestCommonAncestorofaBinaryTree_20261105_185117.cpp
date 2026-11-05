// Last updated: 11/5/2026, 6:51:17 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(!root) return NULL;
14
15        if(root->val==p->val||root->val==q->val) return root;
16        TreeNode* left = lowestCommonAncestor(root->left,p,q);
17        TreeNode* right = lowestCommonAncestor(root->right,p,q);
18
19        if(left&&right) return root;
20
21        return left?left:right;
22        
23
24    }
25};