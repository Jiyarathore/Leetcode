class Solution {
public:
    int maxArea(vector<int>& height) {
         int maxArea = 0;
        int s = 0, e = height.size()-1;

        while(s < e){
            if(height[s] <= height[e]){
                maxArea = max(maxArea,(e-s) * height[s]);
                s++;
            }else{
                maxArea = max(maxArea,(e-s) * height[e]);
                e--;
            }
        }
        return maxArea;
    }
};