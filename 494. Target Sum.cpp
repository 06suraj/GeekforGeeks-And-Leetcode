class Solution {
public:
    map<pair<int,int>,int>dp;
    int solve(vector<int>&nums,int target,int index,int s){
        if(index==-1){
            if(s==target)
                return 1;
            else return 0;
        }
        return solve(nums,target,index-1,s+nums[index])+solve(nums,target,index-1,s-nums[index]);
    }
    
    
    int solve_memoised(vector<int>&nums,int target,int index,int s){
        if(index==-1){
            if(s==target)
                return 1;
            else return 0;
        }
        if(dp.find({index,s})!=dp.end())return dp[{index,s}];
        return dp[{index,s}]=solve_memoised(nums,target,index-1,s+nums[index])+solve_memoised(nums,target,index-1,s-nums[index]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //return solve(nums,target,nums.size()-1,0);     // using recursion+backtracking O(2^n) 
       dp.clear();
        
        return solve_memoised(nums,target,nums.size()-1,0); // using memoised version of above recurrence O(n*target)
    }
};
