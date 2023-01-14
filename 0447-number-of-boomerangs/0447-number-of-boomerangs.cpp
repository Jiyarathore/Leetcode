class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n=p.size();
        int c=0;
        for(int i=0;i<n;i++){
            map<int,int>m;
            for(int j=0;j<n;j++){
                int dist=(((p[i][0]-p[j][0])*(p[i][0]-p[j][0])) + ((p[i][1]-p[j][1])*(p[i][1]-p[j][1])));
                m[dist]++;
            }
            for(auto i:m){
                if(i.second !=0){
                    c+=(i.second*(i.second-1));
                }
            }
        }
        return c;
    }
};