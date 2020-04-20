/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(int till, vector<int>& preorder, int& ind) {
        TreeNode* root = new TreeNode(preorder[ind++]);
        if(ind < preorder.size() && preorder[ind] < root->val)
            root->left = build(root->val - 1, preorder, ind);
        if(ind < preorder.size() && preorder[ind] <= till)
            root->right = build(till, preorder, ind);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(numeric_limits<int>::max(), preorder, i);
    }
};
