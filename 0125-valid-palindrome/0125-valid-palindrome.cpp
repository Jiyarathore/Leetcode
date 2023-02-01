class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string p;
        string x;
        string u;
        for(int i=0;i<n;i++)
        {
            if(islower(s[i]) ||isdigit(s[i]))
            {
                p+=s[i];
                x+=s[i];
            }
            else if(isupper(s[i]))
            {  u=tolower(s[i]);
                p+=u;
                x+=u;
            }
        }
        reverse(p.begin(),p.end());
        if(p==x) return true;
        return false;
    }
};