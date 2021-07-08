class Solution {
public:
        int dp[101][10001];
    
    int solve(int e,int f){
        if(e==1)return f;
        if(f==1 or f==0)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int mi=INT_MAX;
        int l=1,r=f,k;
        while(l<=r){
            k=l+(r-l)/2;
            int low,high;
            if(dp[e-1][k-1]!=-1)low=dp[e-1][k-1];
            else low=solve(e-1,k-1);
            
            if(dp[e][f-k]!=-1)high=dp[e][f-k];
            else high=solve(e,f-k);
            
            int temp=1+max(low,high);
            if(low<high)l=k+1;
            else r=k-1;
            mi=min(mi,temp);
        }
        dp[e][f]=mi;
        return dp[e][f];
        
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};
