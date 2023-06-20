class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int size=nums.size();
        
        list<int>l;
        vector<int>ans;
        while(j<size){
            
            //removing all elements from list which are lesser than the element we are going to add
            
            while(!l.empty() && l.back()<nums[j]){
                l.pop_back();
            }
//             pushing new wlwment into list
            l.push_back(nums[j]);
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
               
                //if window size reached then push the front element of list into the answer vector
                ans.push_back(l.front());
                
                //if front of list is equal to front element of sliding window 
//then we need to remove that element from list 
//because it is exiting out of current window 
// so we have no use of that element
//hence we remove that element
                
                if(l.front()==nums[i]){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};