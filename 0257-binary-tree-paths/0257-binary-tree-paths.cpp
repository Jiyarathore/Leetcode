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
    
   void Binary(TreeNode* root,vector<string>&res,string str){
       if(root->left==NULL && root->right==NULL){
           res.push_back(str);
           return ;
       }
       
       if(root->left!=NULL){
           Binary(root->left,res, str+"->"+to_string(root->left->val));
       }
       
       if(root->right!=NULL){
           Binary(root->right,res, str+"->"+to_string(root->right->val));
       }
   }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(root==NULL) return res;
        
         Binary(root,res, to_string(root->val));
        return res;
    }
};