class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')
                continue;
            
            string temp;
            
//             iterate till we doesn't traverse the whole string and doesn't encounter the last /
            
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            
            if(temp == ".")
                continue;
            
//             pop the top elemet from stack if existe
            else if(temp==".."){
                if(!st.empty())
                    st.pop();
            }
            
            else
//                 push directory file name to stack
                st.push(temp);
            
        }
        
//         ading all stack elements to res;
        
        while(!st.empty()){
            res="/" + st.top() + res;
            st.pop();
        }
        
//         if no direxctory or file is present
        if(res.size()==0)
            return "/";
        
        return res;
    }
};