class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n==0)    return "0";
        if(d==1)    return to_string(n);
        if(d==-1)    return to_string((long)fabs(n));
        string ans="";
        if((n<0 && d>0) || (n>0 && d<0))    ans += "-";
        n = abs(n);
        d = abs(d);
        ans += to_string(n/d);
        long long rem = n%d;
        if(!rem)    return ans;
        else    ans += ".";
        unordered_map<int,int>num;
        while(rem!=0)
        {
            if(num.find(rem)!=num.end())    
            {
                ans.insert(num[rem],"(");
                ans += ")";
                return ans;
            }
            num[rem] = ans.length();
            rem *= 10;
            ans += to_string(rem/d);
            rem %= d;
        }
        return ans;
    }
};