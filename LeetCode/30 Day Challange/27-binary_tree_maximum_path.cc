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
    const int ninf = -1e9;
    
    public:
    pair<int, int> solve(TreeNode* root) {
        if(!root)
            return make_pair(ninf, ninf);
        
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        
        int path = root->val + max({l.first, r.first, 0});
        int subtree = max({path, l.second, r.second, l.first + r.first + root->val});
        
        return make_pair(path, subtree);
    }
    
    int maxPathSum(TreeNode* root) {
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }
};
