class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n= words.size();
        int m= words[0].size();
        if(s.size() < n*m) return ans;
        
        for(int i=0;i<=s.size()-(n*m);i++){
            unordered_map<string,int>map;
            for(int j=0;j<n;j++){
                map[words[j]]++;
            }
            
            int t;
            for(t=0;t<n;t++){
                string str = s.substr(i+t*m,m);
                if(map.count(str)==0) break;
                
                else{
                    if(map[str]!=0){
                        map[str]--;
                    }
                    else break;
                }
            }
            if(t==n) ans.push_back(i);
        }
        return ans;
    }
};