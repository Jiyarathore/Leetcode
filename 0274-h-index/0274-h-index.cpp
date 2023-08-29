class Solution {
public:
    int hIndex(vector<int>& citations) {
//         TC O(nlogn)
        sort(citations.begin(), citations.end());
        
        int h=citations.size();
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=h) return h;
            
            else{
                if(h==1 && citations[i]!=0) return 1;
                
                h--;
            }
        }
        return h;
    }
};