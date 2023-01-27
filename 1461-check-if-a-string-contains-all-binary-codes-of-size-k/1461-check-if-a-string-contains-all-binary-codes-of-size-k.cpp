class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k){
            return false;
        }
        unordered_set<string>st;
        
        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k));
        }
        if(st.size()==pow(2,k)){
            return true;
        }
        else{
            return false;
        }
    }
};