class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if(a.size()==0) return 0;
        
        int i=0;
        for(int j=1;j<a.size();j++){
            if(a[j]!=a[i]){
                i++;
                a[i]=a[j];
            }
        }
        return i+1;
    }
};