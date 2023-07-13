class Solution {
public:
    
    bool rotated(string s,string goal,int rotation){
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[(i+rotation)%goal.length()]) return false;
        }
        return true;
    }
    
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s.length()==0) return true;
        
        for(int i=0;i<s.length();i++){
            if(rotated(s,goal,i)) return true;
        }
        return false;
    }
};