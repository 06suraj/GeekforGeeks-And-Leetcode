class Solution {
public:
    const int mod=1e9+7;
    int dp[501][10001];
    int solve(int steps,int arrlen,int curr){
        if(curr==1 and steps==0)return 1;
        else if(steps==0 or curr<=0 or curr>arrlen)return 0;
        if(dp[steps][curr]!=-1)return dp[steps][curr];
        int right=0,left=0,stay=0;
        right=solve(steps-1,arrlen,curr+1)%mod;
        left=solve(steps-1,arrlen,curr-1)%mod;
        stay=solve(steps-1,arrlen,curr)%mod;
        return dp[steps][curr]=((left%mod+right%mod)%mod+stay%mod)%mod;
    }
    
    int numWays(int steps, int arrlen) {
        memset(dp,-1,sizeof(dp));
        return solve(steps,arrlen,1)%mod;
    }
};
