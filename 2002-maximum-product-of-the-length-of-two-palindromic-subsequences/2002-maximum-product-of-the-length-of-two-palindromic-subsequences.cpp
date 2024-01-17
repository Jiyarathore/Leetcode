class Solution {
public:
    
    int ans=0;
    bool ispal(string &st){
        int i=0,j=st.length()-1;
        while(i<j){
            if(st[i]!=st[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void temp(string &s, int i, string a, string b){
        if(i==s.length()){
            if(ispal(a) && ispal(b)){
                ans=max(ans, (int)(a.length()*b.length()));
            }
            return;
        }
        
        temp(s,i+1,a+s[i],b);
        temp(s,i+1,a,b+s[i]);
        temp(s,i+1,a,b);
    }
    
    int maxProduct(string s) {
        temp(s,0,"","");
        return ans;
    }
};