class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sz=n*m;
        int low=0,high=sz-1;
        
        while(low<=high){
            int mid=(high+low)/2;
            if(matrix[mid/n][mid%n]==target) return true;
            
            else if(matrix[mid/n][mid%n]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};