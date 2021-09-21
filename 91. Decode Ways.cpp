class Solution {
public:
    int memo[101];
    
    int solve_recur(string s,int index,int len){
        if(index==len)return 1;
        if(s[index]=='0')return  0;
        int cnt1=solve_recur(s,index+1,len),cnt2=0;
        if(index!=len-1){
            if((s[index]-'0')*10+(s[index+1]-'0')>=1 and (s[index]-'0')*10+(s[index+1]-'0')<=26)
                cnt2=solve_recur(s,index+2,len);
        }
        return cnt1+cnt2;
    }
    
    int solve_memo(string s,int index,int len){
        if(index==len)return 1;
        if(s[index]=='0')return  0;
        
        int cnt1=0,cnt2=0;
        
        if(memo[index+1]!=-1)
        cnt1=memo[index+1];
        else cnt1=solve_memo(s,index+1,len);
        
        if(index!=len-1){
            if((s[index]-'0')*10+(s[index+1]-'0')>=1 and (s[index]-'0')*10+(s[index+1]-'0')<=26)
            {
                if(memo[index+2]!=-1)cnt2=memo[index+2];
                else cnt2=solve_memo(s,index+2,len);
            }
        }
        return memo[index]=cnt1+cnt2;
    }
    
    
    int numDecodings(string s) {
        // 1 .this recursive solution will give tle as the total t.c =O(2^n);
        // int sol_rec=solve_recur(s,0,s.size());  
        
        // 2. this memoised solution will have a t.c =O(N); 
        memset(memo,-1,sizeof(memo));
        int sol_memo=solve_memo(s,0,s.size());  
        // return sol_memo;
        
        //3. this is a a normal tabulation dp approach having same t.c. as memoised version
        int n=s.size();
        int dp[n+1];
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')dp[i]=0;
            else {
                dp[i]=dp[i+1];
                if(i!=n-1 and (s[i]-'0')*10+(s[i+1]-'0')>=1 and (s[i]-'0')*10+(s[i+1]-'0')<=26)
                    dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};
