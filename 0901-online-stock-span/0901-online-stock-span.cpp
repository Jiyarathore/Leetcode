class StockSpanner {
public:
    StockSpanner() {
        
    }
     stack<pair<int,int>>stack;
    int next(int price) {
        
        int days=1;
        while(!stack.empty() && stack.top().first<=price){
            days+=stack.top().second;
            stack.pop();
        }
        stack.push({price,days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */