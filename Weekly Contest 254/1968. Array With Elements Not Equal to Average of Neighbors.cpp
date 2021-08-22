class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        sort(nums.begin(),nums.end());
        for(int i=1;i<ans.size();i=i+2){
            ans[i]=nums[nums.size()-1];
            nums.pop_back();
        }
        for(int i=0;i<ans.size();i=i+2){
            ans[i]=nums[nums.size()-1];
            nums.pop_back();
        }
       // for(int i:nums)cout<<i<<" ";
        return ans;
        
    }
};
