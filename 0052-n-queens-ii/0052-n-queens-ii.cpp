class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>>board(n, vector<bool>(n,false));
        return solve(board,0);
    }
    
    bool issafe(vector<vector<bool>>&board, int row, int col){
        int n=size(board);
        for(int i=0;i<=row;i++){
            if(board[i][col]==true) return false;
            
            if(row-i>=0 && col-i>=0 && board[row-i][col-i]) return false;
             if(row-i>=0 && col+i<n && board[row-i][col+i]) return false;
        }
        return true;
    }
    
    int solve(vector<vector<bool>>&board, int row){
        if(row==size(board)) return 1;
        int c=0;
        for(int col=0;col<size(board);col++){
            if(issafe(board,row,col)){
                board[row][col]=true;
                c+=solve(board,row+1);
                board[row][col]=false;
            }
        }
        return c;
    }
};