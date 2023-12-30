class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>count(26,0);
        
        for(string word:words){
            for(char c:word){
                count[c-'a']++;
            }
        }
        
        int n=words.size();
        for(int val:count){
            if(val%n!=0) return false;
        }
        return true;
    }
};