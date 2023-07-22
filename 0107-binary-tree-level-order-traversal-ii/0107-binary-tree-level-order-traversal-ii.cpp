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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        if(root==NULL) return ans;
        q.push(root);
        
        stack<vector<int>>s;
        
        
        
        while(!q.empty()){
            vector<int>v;
            int len=q.size();
            
            while(len--){
                TreeNode* temp=q.front();
                q.pop();
                
                v.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                
                if(temp->right) q.push(temp->right);
            }
            s.push(v);
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};