class Solution {
public:
     int memo[30001][2];
    int solve_memo(vector<int>&prices,int index,int sell,int prev){
        if(index>=prices.size())return 0;
        
        if(memo[index][sell]!=-1)return memo[index][sell];
        
        int take=0,not_take=0;
         if(sell)
            take=solve_memo(prices,index+1,0,0)+prices[index];

        else take=solve_memo(prices,index+1,1,prices[index])-prices[index];
        
        not_take=solve_memo(prices,index+1,sell,prev);
        
        return memo[index][sell]=max(take,not_take);
        
    }
    int maxProfit(vector<int>& prices) {
         memset(memo,-1,sizeof(memo));
        
        
        // return solve_memo(prices,0,0,0); // O(N) TIME AND O(N) SPACE
        
        // HILL VALLEY  O(N) TIME AND O(1) SPACE 
        int maxi=-1,mini=-1,n=prices.size(),ans=0;
        for(int i=0;i<n;i++){
            if(mini==-1)mini=prices[i];
            if(prices[i]>maxi)maxi=prices[i];
            else {
                ans+=maxi-mini;
                maxi=prices[i],mini=prices[i];
            }
        }
        ans+=maxi-mini;
        return ans;
        
    }
};
