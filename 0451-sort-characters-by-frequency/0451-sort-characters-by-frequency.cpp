class Solution {
public:
//     By map
//     static bool comp(pair<char,int>&a,pair<char,int>&b){
//         return a.second>b.second;
//     }
    
//     string frequencySort(string s) {
//         map<char,int>m;
//         for(char ch:s){
//             m[ch]++;
//         }
//         vector<pair<char,int>>v;
//         for(auto i:m){
//             v.push_back(i);
//         }
//         sort(v.begin(),v.end(),comp);
//         string ans="";
//         int maxi=INT_MIN;
//         for(auto i:v){
//             int t=i.second;
//             while(t--){
//                 ans+=i.first;
//             }
//         }
//         return ans;
//     }
    
    
    // BY HEAP
    string frequencySort(string s){
        unordered_map<char,int>m;
        for(char ch:s){
            m[ch]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            int k=pq.top().first;
            char c=pq.top().second;
            while(k!=0){
                ans+=c;
                k--;
            }
            pq.pop();
        }
     return ans;   
    }
    
};