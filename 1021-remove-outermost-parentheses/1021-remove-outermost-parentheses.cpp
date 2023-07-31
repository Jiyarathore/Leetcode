class Solution {
public:
    string removeOuterParentheses(string s) {
//         By stack
        stack<char>st;
        string ans="";
        
        for(auto c:s){
            if(c=='('){
                if(st.size()>0){
                    ans+=c;
                }
                st.push(c);
            }
            else if(c==')'){
                if(st.size()>1){
                    ans+=c;
                }
                st.pop();
            }
        }
        return ans;
    }
};