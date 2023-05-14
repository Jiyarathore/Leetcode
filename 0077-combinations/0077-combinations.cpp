class Solution {
    
    void combined(int n,int k,vector<vector<int>>&output, vector<int>&temp, int start){
        if(temp.size()==k){
            output.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            combined(n,k,output,temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>output;
        vector<int>temp;
        combined(n,k,output,temp,1);
        return output;
    }
};