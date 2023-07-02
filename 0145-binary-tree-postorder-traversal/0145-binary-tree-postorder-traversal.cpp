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
//     Recursive sol
//     void postorderfun(vector<int>&postorder,TreeNode* root){
//         if(root==NULL) return;
        
//         postorderfun(postorder,root->left);
//         postorderfun(postorder,root->right);
//         postorder.push_back(root->val);
//     }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>postorder;
        // postorderfun(postorder,root);
        // return postorder;
        
//         Ierative sol using 2 stacks
        
        vector<int>postOrder;
        if(root==NULL) return postOrder;
        
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        
        s1.push(root);
        
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        
        while(!s2.empty()){
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        return postOrder;
    }
};