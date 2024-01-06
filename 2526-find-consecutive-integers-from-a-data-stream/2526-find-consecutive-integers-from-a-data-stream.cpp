class DataStream {
public:
    
    int val=0,kmax=0;
    queue<int>q;
    unordered_map<int,int>hm;
    
    DataStream(int value, int k) {
        val=value;
        kmax=k;
    }
    
    bool consec(int num) {
        
        q.push(num);
        hm[num]++;
        if(q.size() > kmax){
            int x = q.front();
            q.pop();
            hm[x]--;
            if(hm[x] == 0){
                hm.erase(x);
            }
        }
        if(q.size() < kmax)
            return false;
        if(hm.size() == 1){
            // This part is only done to verify if the queue only has all the elements of value "value"
            for(auto it:hm){
                if(it.first == val)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */