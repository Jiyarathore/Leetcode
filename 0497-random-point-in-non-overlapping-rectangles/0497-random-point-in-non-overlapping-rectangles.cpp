class Solution {
public:
    
     int N;
    long int ar;
    vector<vector<int>> rec;
    vector<long int> su;
    Solution(vector<vector<int>>& rects) {
        N = rects.size();
        ar = 0;
        for(auto x: rects){
            ar += (x[2]-x[0]+1)*(x[3]-x[1]+1);
            su.push_back(ar);
        }
        rec = rects;
    }
    
    vector<int> pick() {
        int rval = (rand()%ar);
        int ithrec = upper_bound(su.begin(), su.end() , rval) - su.begin();
        long int x = rec[ithrec][2] - rec[ithrec][0] + 1; // number of x points 
        long int y = rec[ithrec][3] - rec[ithrec][1] + 1; // number of y points
        // Now according to area
        // rval = su[ithrec] - rval;
        int fx = rec[ithrec][0] + (rand()%(x));
        int fy = rec[ithrec][1] + (rand()%(y));
        return {fx,fy};
    }
};
// https://www.youtube.com/watch?v=8kwPXbTMSnk

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */