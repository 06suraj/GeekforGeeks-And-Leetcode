class Solution {
public:
    int memo[101][101];
    int solve_recur(string s1,string s2,string s3,int i,int j,int k){
        if(i==-1 and j==-1 and k==-1)return 1;
        if(k==-1)return 0;
        int ans=0;
        if(i>=0 and s1[i]==s3[k])ans=solve_recur(s1,s2,s3,i-1,j,k-1);
        if(j>=0 and s2[j]==s3[k])ans=ans|(solve_recur(s1,s2,s3,i,j-1,k-1));
        return ans;
        
    }
    
    int solve_memo(string s1,string s2,string s3,int i,int j,int k){
        if(i==s1.size() and j==s2.size() and k==s3.size())
            return 1;
        if(k==s3.size())return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        int ans=0;
        if(i<s1.size() and s1[i]==s3[k])ans=solve_memo(s1,s2,s3,i+1,j,k+1);
        if(j<s2.size() and s2[j]==s3[k])ans|=solve_memo(s1,s2,s3,i,j+1,k+1);
        return memo[i][j]=ans;
        
    }
         
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0,k=0;
        // return solve_recur(s1,s2,s3,i,j,k);  // RECURSIVE APPROACH WITH T.C O(2^(N+M))
        
        memset(memo,-1,sizeof(memo));
        // return solve_memo(s1,s2,s3,i,j,k);  // MEMOISATION WITH T.C O(N*M)
        
        
        // TABULATION
        if(s1.size()+s2.size()!=s3.size())return 0;
        int dp[s1.size()+1][s2.size()+1];
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0 and j==0)dp[i][j]=1;
                else if(i==0){
                   dp[i][j]=(dp[i][j-1]&&(s2[j-1]==s3[i+j-1]));
                }else if(j==0){
                     dp[i][j]=(dp[i-1][j]&&(s1[i-1]==s3[i+j-1]));
                }
                else{
                    if(s1[i-1]==s3[i+j-1])dp[i][j]=dp[i-1][j];
                    else dp[i][j]=0;
                    if(s2[j-1]==s3[i+j-1])dp[i][j]=(dp[i][j]||dp[i][j-1]);
                }
            }
        }
         return dp[s1.size()][s2.size()];
    }
};
