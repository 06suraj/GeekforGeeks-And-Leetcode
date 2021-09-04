class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i+k-1<nums.size())ans=min(ans,nums[i]-nums[i+k-1]);
        }
        return ans;
    }
};
