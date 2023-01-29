class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
            
            int ans=special[0]-bottom;
            
            for(int i=1;i<special.size();i++){
                int x=special[i]-special[i-1]-1;
                ans= max(ans,x);
            }
            ans= max(ans, top-special[special.size()-1]);
        
        return ans;
    }
};