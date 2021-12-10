class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lb=0,ub=nums.size()-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(mid==nums.size()-1){
                if(mid==0)return nums[mid];
                if(nums[mid]!=nums[mid-1])
                    return nums[mid];
            }else if(mid==0){
                if(nums[mid]!=nums[mid+1])
                    return nums[mid];
            }else{
                int index;
                if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])return nums[mid];
                else if(nums[mid]==nums[mid-1]) index=mid-1;
                else index=mid;
                if((nums.size()-index)%2)lb=mid+1;
                else ub=mid-1;
            }
        }
        return nums[0];
    }
};
