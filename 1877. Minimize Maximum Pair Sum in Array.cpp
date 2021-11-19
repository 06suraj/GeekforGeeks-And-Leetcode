class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1,j=nums.size()-2,sum=nums[i-1]+nums[j+1];
        while(i<=j){
            sum=max(sum,nums[i]+nums[j]);
            i++,j--;
        }
        return sum;
    }
};
