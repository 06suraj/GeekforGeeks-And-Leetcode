class Solution{
public:
int  

   int solve(string& s,int i,int j,bool isbool){
       if(i>j)return 0;
       if(i==j){
           if(isbool){
               return s[i]=='T';
           }else
           return s[i]=='F';
       }
       
   if(dp[i][j][isbool]!=-1)return dp[i][j][isbool];
    
    int cnt=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int lt,lf,rt,rf;
        
        if(dp[i][k-1][1]!=-1)
        lt=dp[i][k-1][1];
        else lt=solve(s,i,k-1,1);
        
        if(dp[i][k-1][0]!=-1)
        lf=dp[i][k-1][0];
        else lf=solve(s,i,k-1,0);
        
        if(dp[k+1][j][1]!=-1)
        rt=dp[k+1][j][1];
        else rt=solve(s,k+1,j,1);
        
        if(dp[k+1][j][0]!=-1)
        rf=dp[k+1][j][0];
        else rf=solve(s,k+1,j,0);
        
        
        if(s[k]=='|'){
            if(isbool==1){
                cnt+=lf*rt+rf*lt+lt*rt%1003;
            }else{
                cnt+=lf*rf;
            }
        }else if(s[k]=='&'){
            if(isbool){
                cnt+=rt*lt;
            }else{
                 cnt+=lf*rt+rf*lt+lf*rf;
            }
        }else{
            if(isbool){
                cnt+=lf*rt+rf*lt;
            }else
            cnt+=lf*rf+lt*rt;
        }
        
  }
  
  dp[i][j][isbool]=cnt%1003;
   return cnt%1003;
  
   }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return(solve(S,0,N-1,1));
    }
};
