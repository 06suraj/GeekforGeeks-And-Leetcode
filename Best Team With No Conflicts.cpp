class Solution {
public:
    int memo[1001][1001];
    int solve(vector<pair<int,int>>&basket,int index,int prev){
         if(index>=basket.size())return 0;
         if(prev!=-1 and memo[index][prev]!=-1)return memo[index][prev];
         int include=0,exclude=0,temp=0;
         if(prev==-1 or basket[index].second>=basket[prev].second or basket[index].first==basket[prev].first)
              include=basket[index].first+solve(basket,index+1,index);
        exclude=solve(basket,index+1,prev);
       if(prev==-1)return max(include,exclude);
       return  memo[index][prev]=max(include,exclude);
     
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(memo,-1,sizeof(memo));
       vector<pair<int,int>>basket;
        for(int i=0;i<scores.size();i++){
            basket.push_back({scores[i],ages[i]});
        }
        sort(basket.begin(),basket.end());
        // return solve(basket,0,-1);  // memoisation
        
        int n=ages.size(),dp[n],ans=0;
        for(int i=0;i<n;i++)dp[i]=basket[i].first,ans=max(ans,dp[i]);
        for(int i=0;i<n;i++){
            int age=basket[i].second,score=basket[i].first,maxscore=dp[i];
            for(int j=i+1;j<n;j++){
                if(basket[j].second>=age or basket[j].first==score){
                    if(dp[j]<=dp[i]+basket[j].first){
                        dp[j]=dp[i]+basket[j].first;
                        ans=max(ans,dp[j]);
                    }
                }
            }
        }
        return ans;
    }
};
