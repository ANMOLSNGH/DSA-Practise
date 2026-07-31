/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int i, int j) {
        if(i > j) return NULL;
        
        int maxi = INT_MIN;
        int indx = -1;
        
        for(int k = i; k <= j; k++) {
            if(nums[k] > maxi) {
                maxi = nums[k];
                indx = k;
            }
        }
        
        TreeNode* root = new TreeNode(maxi);
        
       
        root->left = solve(nums, i, indx - 1);
        root->right = solve(nums, indx + 1, j);
        
        return root;
    } 
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};