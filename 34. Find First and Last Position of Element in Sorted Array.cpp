class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n=nums.size(),lb=0,ub=n-1,src=-1,dst=-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(nums[mid]==target){
                src=mid;
                ub=mid-1;
            }else if(nums[mid]<target){
                lb=mid+1;
            }else ub=mid-1;
        }
        lb=0,ub=n-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(nums[mid]==target){
                dst=mid;
                lb=mid+1;
            }else if(nums[mid]<target){
                lb=mid+1;
            }else ub=mid-1;
        }
        return {src,dst};
        
        
    }
};
