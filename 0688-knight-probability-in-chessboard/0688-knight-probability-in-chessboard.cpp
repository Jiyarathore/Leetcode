class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        //no moves so probability 1
        if(k==0) return 1.0;
        
        //parent chess board
        vector<vector<double>>parentBoard(n,vector<double>(n,0.0));
        
        //child chess board
        vector<vector<double>>childBoard(n,vector<double>(n,0.0));
        
        //row and col offset for generating next move or child positions
        int rowoffset[]={-2,-2,-1,-1,2,2,1,1};
        int coloffset[]={1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        
        //initial position probability 1
        parentBoard[r][c]=1.0;
        for(int i=0;i<k;i++){
            for(int p=0;p<n;p++){
                for(int q=0;q<n;q++){
                    
                    //calculate child position probabitilty once from parent position probability
                    double moveprob= parentBoard[p][q]/8.0;
                    
                    //generate valid child position
                    for(int w=0;w<8;w++){
                        cx=p+rowoffset[w];
                        cy=q+coloffset[w];
                        
                        //update child position probability
                        if(cx>=0 && cx<n && cy>=0 && cy<n){
                            childBoard[cx][cy]+=moveprob;
                        }
                    }
                }
                
            }
            
            parentBoard=childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(n,0.0));
        }
        double knightProb=0.0;
        
        //loop through parent board after k steps and sum up all probability
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
            knightProb+=parentBoard[p][q];    
            }
            
        }
        return knightProb;
    }
};