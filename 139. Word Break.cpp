class Solution {
public:
    unordered_map<string,bool>memo;
    
    int solve_recur(string s,unordered_set<string>&ma){
        if(s.empty())return 1;
        
        int n=s.size();
        for(int i=1;i<=n;i++){
            if(ma.find(s.substr(0,i))!=ma.end() and solve_recur(s.substr(i, n-i),ma))return 1;
        }
        return 0;
    }
    
    int solve_memo(string s,unordered_set<string>&ma){
         if(s.empty())return 1;
        
       if(memo.find(s)!=memo.end())return memo[s];
        
        int n=s.size();
        for(int i=1;i<=n;i++){
            if(ma.find(s.substr(0,i))!=ma.end() and solve_memo(s.substr(i, n-i),ma)){
            return memo[s]=1;
            }
        }
        return memo[s]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        unordered_set<string>ma;
        for(string s1:wordDict)ma.insert(s1);
        if(ma.find(s)!=ma.end())return 1;
        // return(solve_recur(s,ma));    // RECURSION
        
        // return(solve_memo(s,ma));    //MEMOISATION
        
        //TABULATION
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]){
                    if(ma.find(s.substr(j,i-j))!=ma.end())
                    {  dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
