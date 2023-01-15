class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>>m;
        int ans=1e9;
        for(int i=0;i<cards.size();i++){
            m[cards[i]].push_back(i);
        }
        for(auto it:m){
           if(it.second.size()>1){
               int c=1e9;
               for(int i=0;i<it.second.size()-1;i++){
                  c=min(c,it.second[i+1]-it.second[i]+1);
               }
               ans=min(ans,c);
           }
            
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};