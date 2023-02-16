//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

long long func(int i,int j){
    if(i==0 && j==0) return 1;
    
    if(i<0 || j<0) return 0;
    
    int up=func(i-1,j);
    int left = func(i,j-1);
    return up+left;
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    return func(m-1,n-1);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends