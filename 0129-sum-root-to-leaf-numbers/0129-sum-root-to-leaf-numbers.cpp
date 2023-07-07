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
//     recursion 
//     int sumNumbers(TreeNode* root) {
//         int currentSum=0;
//         return sum(root,currentSum);
//     }
    
//     int sum(TreeNode* root, int currentSum){
//         if(root==NULL) return 0;
        
//         currentSum= currentSum*10 + root->val;
        
//         if(root->left==NULL && root->right==NULL) return currentSum;
        
//         int leftSum=sum(root->left,currentSum);
//         int rightSum=sum(root->right,currentSum);
        
//         return leftSum+rightSum;
//     }
    
//     iterayive 
    
     int sumNumbers(TreeNode* root) {
         int totalSun=0;
         queue<pair<TreeNode*,int>>q;
         q.push({root,0});
             int totalSum=0;         
         while(!q.empty()){

             auto [root,currentSum]=q.front();
             q.pop();
             
             currentSum=currentSum*10 + root->val;
             
             if(root->left==NULL && root->right==NULL) totalSum+=currentSum;
             
             if(root->left!=NULL) q.push({root->left,currentSum});
             if(root->right!=NULL) q.push({root->right,currentSum});
         }
         return totalSum;
     }
    
    
};