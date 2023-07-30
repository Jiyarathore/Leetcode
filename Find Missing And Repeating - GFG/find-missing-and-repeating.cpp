//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int>m;
        vector<int>v;
        int sum=0,sum2=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            
        }
        for(auto i:m){
            if(i.second>1){
                v.push_back(i.first);
            }
        }
        int c=1;
        for(auto i:m){
         if(i.first!=c){
             v.push_back(c);
             break;
         }   
         else{
             c++;
         }
        }
        
        if(m.find(c)==m.end()) v.push_back(n);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends