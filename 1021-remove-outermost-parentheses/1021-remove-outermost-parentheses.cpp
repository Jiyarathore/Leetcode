class Solution {
public:
    string removeOuterParentheses(string s) {
//         By stack
//         stack<char>st;
//         string ans="";
        
//         for(auto c:s){
//             if(c=='('){
//                 if(st.size()>0){
//                     ans+=c;
//                 }
//                 st.push(c);
//             }
//             else if(c==')'){
//                 if(st.size()>1){
//                     ans+=c;
//                 }
//                 st.pop();
//             }
//         }
//         return ans;
        
//         By simple
        
        string ans="";
        int openParentheses=0;
        for(char c:s){
            if(c=='('){
                if(openParentheses>0){
                    ans+=c;
                }
                openParentheses++;
            }
            
            else if(c==')'){
                if(openParentheses>1){
                    ans+=c;
                }
                openParentheses--;
            }
        }
        return ans;
    }
};