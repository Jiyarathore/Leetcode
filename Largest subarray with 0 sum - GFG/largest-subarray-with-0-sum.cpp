//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// /*You are required to complete this function*/ {15,-2,2,-8,1,7,10,23}
// Output: 5

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int>presum;
        
        int sum=0 ;
        int max_len=0;
        
        for(int i=0;i<n;i++){
            sum+=a[i];
            
            if(a[i]==0 && max_len==0)
            max_len=1;
            
            if(sum==0)
            max_len=i+1;
            
            // look for this in hash tablw
            if(presum.find(sum)!=presum.end()){
                // if this sum is seen before, them update maxlen
                max_len=max(max_len, i-presum[sum]);
            }
            else{
                // else insert this sum with index in hash table
                presum[sum]=i;
            }
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends