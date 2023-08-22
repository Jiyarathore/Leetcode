class Solution {
public:
    string convertToTitle(int coloumnNumber) {
        string ans;
        
        while(coloumnNumber){
            coloumnNumber--;
            
            ans=ans+(char)((coloumnNumber)%26 + 'A');
            coloumnNumber=(coloumnNumber)/26;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};