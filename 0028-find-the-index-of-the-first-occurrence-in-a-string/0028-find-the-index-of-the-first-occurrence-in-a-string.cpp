class Solution {
public:
    int strStr(string haystack, string needle) {
        int m= needle.length();
        int n = haystack.length();
        
        for(int windowstart=0;windowstart<=n-m;windowstart++){
            for(int i=0;i<m;i++){
                if(needle[i]!=haystack[windowstart+i]){
                    break;
                }
                if(i==m-1){
                    return windowstart;
                }
            }
        }
        return -1;
    }
};