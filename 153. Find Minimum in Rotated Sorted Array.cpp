class Solution {
public:
    int findMin(vector<int>& nums) {
        int lb=0,ub=nums.size()-1,ans=-1;
        if (nums[ub] > nums[0] or ub==0) {
      return nums[0];
    }
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
             if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }
            if (nums[mid - 1] > nums[mid]) {
        return nums[mid];
      }
            if(nums[mid]>nums[0])lb=mid+1;
            else{
                ub=mid-1;
            }
        }
        return -1;
        
    }
};
