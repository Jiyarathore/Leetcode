//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
   void merge(long long arr[], long long l, long long m, long long r,long long &ans)
    {
         vector<long long> temp;
         long long left=l,right=m+1;
         while(left<=m && right<=r){
             if(arr[left]<=arr[right]){
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 right++;
                 ans+=(m-left+1);
             }
         }
         while(left<=m){
              temp.push_back(arr[left]);
                 left++;
         }
         while(right<=r){
               temp.push_back(arr[right]);
                 right++;
          }
         long long n=temp.size();
         for(long long i=0;i<n;i++){
             arr[i+l]=temp[i];
         }
    }
    public:
    void mergeSort(long long arr[], long long l, long long r,long long &ans)
    {
        if(l==r) return;
        long long m=(l+r)/2;
        mergeSort(arr,l,m,ans);
        mergeSort(arr,m+1,r,ans);
        merge(arr,l,m,r,ans);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans=0;
        mergeSort(arr,0,N-1,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends