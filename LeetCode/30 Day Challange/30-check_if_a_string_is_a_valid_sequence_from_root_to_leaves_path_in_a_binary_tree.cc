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
    
    bool dfs(TreeNode* curr, vector<int>& arr, int i) {
        if(i == arr.size())
            return !curr->left && !curr->right;
        
        if(curr->right && curr->right->val == arr[i])
            if(dfs(curr->right, arr, i + 1))
                return true;
        if(curr->left && curr->left->val == arr[i])
            if(dfs(curr->left, arr, i + 1))
                return true;
        return false;
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 1);
    }
};
