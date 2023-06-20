//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
  int k = pat.size();
  int n = txt.size();
  int ans = 0;
  unordered_map<char, int>mp;
  for(int i = 0; i < k; i++){
      mp[pat[i]]++;
  }
  int i = 0, j = 0;
  int cnt = mp.size();
  
  while(j < n){
      //cal
      char x = txt[j];
      if(mp.find(x) != mp.end()){
          mp[x]--;
          //txt ka ek char udd gya..ab isse wapas layenge jab ans nikal jayega hamara
          if(mp[txt[j]] == 0)cnt--;
      }
      
      if(j-i+1 < k){
          j++;
      }
      else if(j-i+1 == k){
          //operation and ans
          if(cnt == 0){
              ans++;
          }
          // txt ka 1 char udd gya toh wapas bhi toh lekar aana hai map mei otherwise next window mei anagram  kaise check karenge
          // rhi baat freq ki toh ek window mei hum ek udda rhe hai toh map mei ek hi dalenge na.
          if(mp.find(txt[i]) != mp.end()){
              mp[txt[i]]++;
              if(mp[txt[i]] == 1)cnt++;
          }
          i++;
          j++;
      }
  }
  return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends