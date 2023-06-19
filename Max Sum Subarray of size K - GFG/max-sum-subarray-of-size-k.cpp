//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &A, int N){
        // code here 
        int i=0;
         int j=0;
         long long sum=0;
         long long res=INT_MIN;
         while(j<N){
             sum+=A[j];
             if(j-i+1 < K){
                 j++;
             }
             else{
                 res=max(res,sum);
                 sum-=A[i];
                 i++;
                 j++;
             }
         }
         return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends