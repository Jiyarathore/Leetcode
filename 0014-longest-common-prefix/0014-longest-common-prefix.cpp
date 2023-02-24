class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        string s="";
        int a=strs.size();
        string n=strs[0],m=strs[a-1];
        
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){
                s+=n[i];
            } 
            else break;
        }
        
        return s;
    }
};