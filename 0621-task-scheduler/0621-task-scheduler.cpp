class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>maxH;
        vector<int>mp(26,0);
        
        for(char i:tasks){
            mp[i-'A']++;
        }
        
        for(int i=0;i<26;i++){
            if(mp[i]!=0) maxH.push(mp[i]);
        }
        
        int time=0;
        while(!maxH.empty()){
            vector<int>remain;
            
            int cycle=n+1;
            
            while(cycle!=0 && !maxH.empty()){
                int maxfreq=maxH.top();
                maxH.pop();
                if(maxfreq>1){
                    remain.push_back(maxfreq-1);
                    
                }
                time++;
                cycle--;
            }
            
            for(int count:remain){
maxH.push(count);
                }
            
            if(maxH.empty()) break;
            time+=cycle;
        }
        
        return time;
    }
};