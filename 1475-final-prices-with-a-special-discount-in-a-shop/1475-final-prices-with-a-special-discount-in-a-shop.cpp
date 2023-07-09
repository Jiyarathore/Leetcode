class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n=prices.size();
        vector<int>discount(n,0);
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                if(st.top()<=prices[i])
                    discount[i]=st.top();
                
                else{
                    while(!st.empty() && (st.top()>prices[i])) st.pop();
                    if(!st.empty()) discount[i]=st.top();
                }
            }
                st.push(prices[i]);
            
            
        }
        
        vector<int>selling_price(n);
        for(int i=0;i<n;i++){
            selling_price[i]=prices[i]-discount[i];
        }
        return selling_price;
    }
};