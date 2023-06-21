class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        int minlen=INT_MAX,start=0;
        for(auto ch:t){
            m[ch]++;
        }
        int i=0,j=0,c=m.size();
        while(j<s.length()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) c--;
            }
            
            if(c==0){
                while(c==0){
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        
                        if(m[s[i]]==1){
                            c++;
                        
                        if(j-i+1<minlen){
                            minlen=j-i+1;
                            start=i;
                        }
                    }
                    }
                
                i++;
            }
        }
        j++;
    }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};