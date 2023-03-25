class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        int n= matrix[0].size();
        int rowst=0;
        int rowend=m-1;
        int colst=0;
        int colend=n-1;
        
        while(rowst<=rowend && colst<=colend){
            
            for(int j=colst;rowst<=rowend && colst<=colend && j<=colend;j++){
                ans.push_back(matrix[rowst][j]);
            }
            rowst++;
            
            for(int i=rowst;rowst<=rowend && colst<=colend && i<=rowend;i++){
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            
            for(int j=colend;rowst<=rowend && colst<=colend && j>=colst;j--){
                ans.push_back(matrix[rowend][j]);
            }
            rowend--;
            
            for(int i=rowend;rowst<=rowend && colst<=colend && i>=rowst;i--){
                ans.push_back(matrix[i][colst]);
            }
            colst++;
        }
        
        return ans;
    }
};