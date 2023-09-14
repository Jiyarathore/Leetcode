class NumArray {
public:
     NumArray(vector<int>& nums) {
        
        size = nums.size();
        
        // build prefix sum table 
        prefixSum = vector<int>(size, 0);

        prefixSum[0] = nums[0];

        for( int k = 1; k < size ; k++){
            prefixSum[k] = prefixSum[k-1] + nums[k];
        }

    }
    
    int sumRange(int left, int right) {
        
        // lookup table from prefixSum
        if( left == 0 ){
            return prefixSum[right];
        
        }else{
            return prefixSum[right] - prefixSum[left-1];    
        }
        
    }
private:
    int size;
    vector<int> prefixSum;
        
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */