class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2)return "11";
           
           string s="11";
           
           for(int i=3;i<=n;i++){
               string temp="";
               s+="$"; //adding extra random string $ to append the count of last value
               
               int c=1;
               
               for(int j=1;j<s.size();j++){
                   //if(prev!= ith value) we need to add frequency then no. afeter it and einitialize it
                   
                   if(s[j-1]!=s[j]) {
                       temp+=to_string(c); //appned the freq
                       temp+=s[j-1]; // append the value
                       c=1; //reintialize it
                       
                   }
                      //value is same i.e (prev==ith value)
                      else{
                          c++;
                      }
               }
                      //update s with temp
                      s=temp;
           }
                      return s;
    }
};