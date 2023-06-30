class Solution {
public:
    
//     Binary search Method
    
//     int firstOccurrence(vector<int>&arr, int n,int k){
//         int low=0;
//         int high=n-1;
//         int first=-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(arr[mid]==k){
//                 first=mid;
//                 high=mid-1;
//             }
//             else if(arr[mid]<k) low=mid+1;
//             else high=mid-1;
//         }
//         return first;
//     }
    
//     int lastOccurrence(vector<int>&arr,int n,int k){
//         int low=0,high=n-1;
//         int last=-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(arr[mid]==k){
//                 last=mid;
//                 low=mid+1;
//             }
//             else if(arr[mid]<k) low=mid+1;
//             else high=mid-1;
//         }
//         return last;
//     }
    
//     vector<int> searchRange(vector<int>& nums, int target) {
//        int n=nums.size();
//         int first=firstOccurrence(nums,n,target);
//         if(first==-1) return {-1,-1};
        
//         int last=lastOccurrence(nums,n,target);
//         return {first,last};
//     }
    
    
//     direct method
    
    int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int l=0,h=n-1,ans=n;

	while(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]>=x){
			ans=mid;
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
    
    int upperBound(vector<int> &arr, int n, int x){
	// Write your code here.	
	int h=n-1,l=0,ans=n;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]>x){
			ans=mid;
			h=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,n,target);
            
            if(lb==n || nums[lb]!=target) return {-1,-1};
        return {lb,upperBound(nums,n,target)-1};
    }
    
};