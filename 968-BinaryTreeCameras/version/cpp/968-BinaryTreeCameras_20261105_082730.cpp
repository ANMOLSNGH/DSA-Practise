// Last updated: 11/5/2026, 8:27:30 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12
13/*
14 postorder
15 0 means node is covered
16 1 means camera installed
17 2 node need camera
18*/
19class Solution {
20public:
21    int minCameraCover(TreeNode* root) {
22       int camera = 0;
23       if(dfs(root,camera)==2) camera++;
24       return camera;
25       
26    }
27
28
29    int dfs(TreeNode* root,int &camera) {
30        if(!root) return 0;
31
32        int left = dfs(root->left,camera);
33        int right = dfs(root->right,camera);
34
35        if(left==2||right==2) {
36            camera++;
37            return 1;
38        }
39
40        if(left==1||right==1) return 0;
41        return 2;
42    }
43};