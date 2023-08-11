class Solution {
public:
    int maxProfit(vector<int>& a) {
        int maxProfit=0;
        for(int i=1;i<a.size();i++){
            maxProfit+=max(a[i]-a[i-1],0);
        }
        return maxProfit;
    }
};