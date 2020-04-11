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
    
    pair<int, int> pathAndDepth(TreeNode* root) {
        pair<int, int> l(0, 0), r(0, 0);
        if(root->left)
            l = pathAndDepth(root->left);
        if(root->right)
            r = pathAndDepth(root->right);
        return make_pair(max({l.first, r.first, r.second + l.second + 1}),
                         max(l.second, r.second) + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        return pathAndDepth(root).first - 1;
    }
};
