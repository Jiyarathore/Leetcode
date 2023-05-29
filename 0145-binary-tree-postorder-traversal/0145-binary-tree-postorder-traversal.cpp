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
    
    void postorderfun(vector<int>&postorder,TreeNode* root){
        if(root==NULL) return;
        
        postorderfun(postorder,root->left);
        postorderfun(postorder,root->right);
        postorder.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        postorderfun(postorder,root);
        return postorder;
    }
};