class Solution {
public:
    int memo[101][101],memo1[101];
    
    int solve_recur(vector<int>&nums,int prev,int index,int n){
        if(index==n)return 0;
        
        if(prev==-1 or index!=prev+1){
            return max((nums[index]+solve_recur(nums,index,index+1,n)),solve_recur(nums,prev,index+1,n));
        }else return solve_recur(nums,prev,index+1,n);
    }
    
    int solve_memo(vector<int>&nums,int prev,int index,int n){
        if(index==n)return 0;
        
        if(prev!=-1){
         if(memo[prev][index]!=-1)return memo[prev][index];
            
            if(index!=prev+1)
                return memo[prev][index]=max((nums[index]+solve_memo(nums,index,index+1,n)),solve_memo(nums,prev,index+1,n));
            else return memo[prev][index]=solve_memo(nums,prev,index+1,n);
        }else return max((nums[index]+solve_memo(nums,index,index+1,n)),solve_memo(nums,prev,index+1,n));
    }
    
    
    int solve_memo1(vector<int>&nums,int index)
    {
        if(index<0)return 0;
        
        if(memo1[index]!=-1)return memo1[index];
        
        return memo1[index]=max(nums[index]+solve_memo1(nums,index-2),solve_memo1(nums,index-1));
    }
    
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        // return solve_recur(nums,-1,0,n);  // recursion
        
        memset(memo,-1,sizeof(memo));
        // return(solve_memo(nums,-1,0,n));  // memoisation using index and prev;
        
        memset(memo1,-1,sizeof(memo1));      // memoisation using i-2 and i-1
        // return solve_memo1(nums,n-1);
        
        // tabulation iterative
        int dp[n];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            if(i-2>=0)dp[i]=max(dp[i],nums[i]+dp[i-2]);
            else dp[i]=max(dp[i],nums[i]);
        }
        return dp[n-1];
        
        
        
        
    }
};
