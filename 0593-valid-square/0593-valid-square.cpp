class Solution {
public:
    
    int dis(vector<int>a,vector<int>b){
        return ((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         unordered_set<int> st;
        st.insert(dis(p1,p2));
        st.insert(dis(p1,p3));
        st.insert(dis(p1,p4));
        st.insert(dis(p2,p3));
        st.insert(dis(p2,p4));
        st.insert(dis(p3,p4));
        if (st.size()==2){
            for (auto val: st){
                if (val==0)return false;
            }
            return true;
        }
        return false;
    }
};