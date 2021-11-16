class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=1;             
        int dp[n];
        for(int i=0;i<n;i++)dp[i]=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 and dp[j]<=dp[i])
                {
                    dp[j]=dp[i]+1;
                    ans=max(ans,dp[j]);
                }
            }
        }
        int prev=0;
        vector<int>ans1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==ans and prev%nums[i]==0){
                ans1.push_back(nums[i]);
                prev=nums[i];
                ans=dp[i]-1;
            }
        }
        return ans1;
    }
};
