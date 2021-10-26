class Solution {
public:
    int memo[1001][1001];
    int solve_memo(vector<int>& nums, vector<int>& multipliers,int first,int last,int cnt){
        if(cnt>=multipliers.size())return 0;
        if(memo[first][cnt]!=-1)return memo[first][cnt];
        return memo[first][cnt]=max(nums[first]*multipliers[cnt]+solve_memo(nums,multipliers,first+1,last,cnt+1),nums[last]*multipliers[cnt]+solve_memo(nums,multipliers,first,last-1,cnt+1));
        
    }
    
    int solve_enhanced(vector<int>& nums, vector<int>& multipliers,int first,int cnt){
        if(cnt>=multipliers.size())return 0;
        if(memo[first][cnt]!=-1)return memo[first][cnt];
        int last=nums.size()-1-cnt+first; //(l - 0) + (nums.size() -1 - r) = i => r = nums.size() - 1-i + l ENHANCED VERSION
        return memo[first][cnt]=max(nums[first]*multipliers[cnt]+solve_enhanced(nums,multipliers,first+1,cnt+1),nums[last]*multipliers[cnt]+solve_enhanced(nums,multipliers,first,cnt+1));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(memo,-1,sizeof(memo));
        // return solve_memo(nums,multipliers,0,nums.size()-1,0);
        return solve_enhanced(nums,multipliers,0,0);
    }
};
