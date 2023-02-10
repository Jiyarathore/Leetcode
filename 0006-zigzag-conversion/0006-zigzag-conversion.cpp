class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        
        if(numRows==1){
return s;
        }
        
        if(numRows>=len){
            return s;
            
        }
        int delta =-1; //to keep track of the direction we are supposed to move in
//             either up or down
//             1 means down and -1 means up
            
            int row = 0; // the row number where we are going to append the character 
        
        
        vector<char> res[numRows];
        
        for(auto c:s){
            res[row].push_back(c);
            
            if(row==0 || row==numRows-1) //change direction
                delta*=-1;
            
            row+=delta;
        }
        
        string result = "";
        
        for(auto x:res){
            for(auto y:x){
                result+=y;
            }
        }
        return result;
    }
};