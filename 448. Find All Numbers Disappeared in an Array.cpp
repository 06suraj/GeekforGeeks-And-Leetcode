class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         int n=nums.size();
        int f[n+1];
        memset(f,0,sizeof(f));
        vector<int>ans;
        for(int i:nums)f[i]++;
        for(int i=1;i<=n;i++){
            if(!f[i])ans.push_back(i);
        }
        return ans;
    }
};
