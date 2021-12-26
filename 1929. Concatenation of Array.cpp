class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(2*nums.size());
        int j=0;
        for(int i:nums)ans[j++]=i;
        for(int i:nums)ans[j++]=i;
        return ans;
    }
};
