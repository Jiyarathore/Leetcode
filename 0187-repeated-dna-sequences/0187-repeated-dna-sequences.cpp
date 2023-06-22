class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string,int>m;
        for(int i=0;i+9<s.size();i++){
            string str=s.substr(i,10);
            m[str]++;
        }
        for(auto i:m){
            if(i.second>1){
                res.push_back(i.first);
            }
        }
        
        return res;
    }
};