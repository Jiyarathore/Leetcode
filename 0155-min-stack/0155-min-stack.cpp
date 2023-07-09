class MinStack {
public:
//     TC-O(2N);
//     stack<pair<int,int>>st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         int mini;
//         if(st.empty()){
//             mini=val;
//         }
//         else{
//             mini=min(st.top().second,val);
//         }
//         st.push({val,mini});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
    
//     TC-O(N);
    
     stack<long long>st;
    long long mini;
    MinStack() {
        while(st.empty()==false) st.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long vl=val;
        if(st.empty()){
            mini=vl;
            st.push(vl);
        }
        else{
            if(vl<mini){
                st.push(2*vl*1LL - mini);
                mini=vl;
            }
            else{
                st.push(vl);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el=st.top();
        st.pop();
        
        if(el<mini){
            mini=2*mini - el;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long el=st.top();
        if(el<mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */