class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        string ans="";
        
        for(auto x: s){
            m[x]++;
            
        }
        for(auto i:order){
            if(m.find(i)!=m.end()){
                auto temp = m.find(i);
                int c=temp->second;
                
                string s(c,i);
                ans+=s;
                m.erase(i);
            }
        }
        
        for(auto i:m){
            string s(i.second,i.first);
            ans+=s;
        }
        return ans;
    }
};