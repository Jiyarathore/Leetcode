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
    
//     using dfs
    
//     int dfs(TreeNode* root){
//         if(root==NULL) return 0;
        
// //         if only one of the child is non null, then go in recursion
//         if(root->left==NULL){
//             return 1+dfs(root->right);
//         }
        
//         else if(root->right==NULL){
//             return 1+ dfs(root->left);
//         }
        
// //         both children are non null , call for both childs
//         return 1+ min(dfs(root->left),dfs(root->right));
//     }
    
//     int minDepth(TreeNode* root) {
//     return dfs(root);    
//     }
    
//     using bfd
    
    int minDepth(TreeNode* root){
        if(root==NULL) return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        int depth=1;
        
        while(!q.empty()){
            int qSize=q.size();
            
            while(qSize--){
                TreeNode* node=q.front();
                q.pop();
                
                if(node==NULL) continue;
                
                if(node->left==NULL && node->right==NULL) return depth;
                
                q.push({node->left});
                q.push({node->right});
            }
            depth++;
        }
        return -1;
    }
};