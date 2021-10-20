class Solution {
public:
    int memo[100001][2][3];
     int solve_memo(vector<int>&prices,int index,int sell,int prev,int left){
        if(index>=prices.size())return 0;
        if(left<=0)return 0;
        if(memo[index][sell][left]!=-1)return memo[index][sell][left];
        
        int take=0,not_take=0;
         if(sell)
            take=solve_memo(prices,index+1,0,0,left-1)+prices[index];

        else take=solve_memo(prices,index+1,1,prices[index],left)-prices[index];
        
        not_take=solve_memo(prices,index+1,sell,prev,left);
        
        return memo[index][sell][left]=max(take,not_take);
        
    }
    int maxProfit(vector<int>& arr) {
        memset(memo,-1,sizeof(memo));
        
        
        // return solve_memo(arr,0,0,0,2); //MEMOISATION
        
        // PREPROCESSING FOR EACH INDICES , CHECK FOR MAXIMUM PROFIT FOR ONE TRANSACTION AT LEFT AND ONE TRANSACTION AT RIGHT , THEN CALCULATE FOR MAXIMUM PROFIT BY LEFT[I]+RIGHT[I]
        int n=arr.size();
        vector<int>left(n),right(n);
        int maxi=arr[0],mini=arr[0],ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>maxi){ 
              maxi=arr[i];
              ans=max(ans,maxi-mini);
               left[i]=ans;
            }
            else{
                ans=max(ans,maxi-mini);
                left[i]=ans;
                if(arr[i]<mini)mini=arr[i];
                maxi=arr[i];
            }
        }
       
        maxi=arr[n-1],mini=arr[n-1],ans=0;
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]<mini){ 
              mini=arr[i];
              ans=max(ans,maxi-mini);
              right[i]=ans;
            }
            else{
                ans=max(ans,maxi-mini);
                right[i]=ans;
                if(arr[i]>maxi)maxi=arr[i];
                mini=arr[i];
            }
        }
        
        ans=0;
        for(int i=0;i<n;i++)ans=max(ans,left[i]+right[i]);
        return ans;
        
        
    }
};
