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
//     bool isValidBST(TreeNode* root) {
//         long long int min = -1000000000000, max = 1000000000000;
//         return isVaidbst(root,min, max);
//     }
//     bool isVaidbst(TreeNode* root,  long long int &minval, long long int &maxval){
//         if(root==NULL) return true;
//         if(root->val >=maxval || root->val<=minval) return false;
        
//         return isVaidbst(root->left,minval,root->val) && isVaidbst(root->right,root->val,maxval);
//     }
// };

bool isPossible(TreeNode* root, long long l, long long r){
    if(root == nullptr)  return true;
    if(root->val < r and root->val > l)
        return isPossible(root->left, l, root->val) and 
                                isPossible(root->right, root->val, r);
    else return false;
}

public:
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
};