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
    
//     preorder
    
//     void getAllPaths(TreeNode* root, int targetSum, vector<int>temp,vector<vector<int>>&ans){
//         if(root==NULL) return;
        
//         if(root->left==NULL && root->right==NULL && targetSum==root->val){
//             temp.push_back(root->val);
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(root->val);
//         getAllPaths(root->left,targetSum-root->val,temp,ans);
//         getAllPaths(root->right,targetSum-root->val,temp,ans);
        
//     }
    
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//     vector<vector<int>>ans;
//         getAllPaths(root,targetSum,{},ans);
//         return ans;
//     }
    
    
//     BFS
    
    bool isLeaf(TreeNode *root){
        return root->left==NULL && root->right==NULL;
    }
    
   vector<vector<int>> getAllPaths(TreeNode *root,int targetSum)
{
// Queue stores {TreeNode , Sum From Root To TreeNode, Path containing Nodes From Root To Current Node}
    queue<pair<TreeNode*,pair<int,vector<int> > > > q;
    vector<vector<int>> res;
    if(!root)
        return res;
// Start with Root Node with currentSum == root->val and Path = {root->val}
    q.push({root,{root->val,{root->val}}});
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *treeNode = front.first;
        int currentSum = front.second.first;
        vector<int> currentPath = front.second.second;
//         Check if we reach the leaf node with currentSum equals to TargetSum
        if(isLeaf(treeNode) and currentSum == targetSum)
        {
//          Push one Path into the final Answer
            res.push_back(currentPath);
        }
        if(treeNode->left)
        {
            vector<int> leftPath = currentPath;
            leftPath.push_back(treeNode->left->val);
//          Store the left child with new sum and path,
            q.push({treeNode->left,{currentSum + treeNode->left->val,leftPath}});
        }
        if(treeNode->right)
        {
            vector<int> rightPath = currentPath;
            rightPath.push_back(treeNode->right->val);
//          Store the right child with new sum and path,
            q.push({treeNode->right,{currentSum + treeNode->right->val,rightPath}});
        }
    }
    return res;
}
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        return getAllPaths(root,targetSum);
    }
};