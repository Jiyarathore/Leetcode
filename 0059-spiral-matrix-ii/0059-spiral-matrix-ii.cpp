class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
        
        int m=n,l=1;
        for(int x=0;x<n/2;x++){
            int i=x,j=x;
            
//             righht
            for(int k=0;k<m-1;k++){
                arr[i][j++]=l++;
            }
//             down
            for(int k=0;k<m-1;k++){
                arr[i++][j]=l++;
            }
//             left
            for(int k=0;k<m-1;k++){
                arr[i][j--]=l++;
            }
//             up
            for(int k=0;k<m-1;k++){
                arr[i--][j]=l++;
            }
            m-=2;
        }
        if(n%2!=0) arr[n/2][n/2]=l;
        
        return arr;
    }
    
};