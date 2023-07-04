//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   void help(int num, string ans, int i){
        if(i==num){
            cout<<ans<<" ";
            return;
        }
        
        if(i==0 or ans[i-1]!='1'){
            help(num,ans+'0',i+1);
            help(num, ans+'1', i+1);
        }
        else if(ans[i-1]=='1')
         help(num,ans+'0',i+1);
    }

    void generateBinaryStrings(int num){
        //Write your code
           string ans ="";
        int i=0;
        help(num,ans,i);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends