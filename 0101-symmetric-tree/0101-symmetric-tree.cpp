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
    bool isSymmetric(TreeNode* root) {
         if(!root) return true;
        return isSymmetricHelp(root->left, root->right);
    }
    
    bool isSymmetricHelp(TreeNode* root1, TreeNode* root2){
        if(!root1) return !root2;
        if(!root2) return !root1;
        return (root1->val == root2->val) && isSymmetricHelp(root1->left, root2->right) && isSymmetricHelp(root1->right, root2->left);
    }
};