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
    
    // void preorderfun(vector<int>&preorder, TreeNode* root){
    //     if(root==NULL){return;}
    //     preorder.push_back(root->val);
    //     preorderfun(preorder,root->left);
    //     preorderfun(preorder,root->right);
    // }
    
//     Iteratibve 
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         // vector<int>preorder;
//         // preorderfun(preorder,root);
//         // return preorder;
        
//         vector<int>preorder;
//     if(root==NULL) return preorder;

//     stack<TreeNode*>st;
//     st.push(root);
//     while(!st.empty()){
//         root = st.top();
//         st.pop();
//         preorder.push_back(root->val);

//         if(root->right!=NULL){
//             st.push(root->right);
//         }

//         if(root->left!=NULL){
//             st.push(root->left);
//         }
//     }
//     return preorder;
//     }
    
    //     Morris Traversal treading wlaa
    vector<int> preorderTraversal(TreeNode* root){
        vector<int>preorder;
        TreeNode *cur=root;
        
        while(cur!=NULL){
            if(cur->left==NULL){
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right=cur;
                    preorder.push_back(cur->val);
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return preorder;
    }
};