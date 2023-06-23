//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long kthsmall(long long A[], long long N, long long k){
        priority_queue<long long>maxHeap;
        for(long long i=0;i<N;i++){
            maxHeap.push(A[i]);
            
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first=kthsmall(A,N,K1);
        long long second=kthsmall(A,N,K2);
        
        long long sum=0;
        for(long long i=0;i<N;i++){
            if(A[i]>first && A[i]<second){
                sum+=A[i];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends