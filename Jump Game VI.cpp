class Solution {
public:
    unordered_map<int,int>memo;
    int solve_memo(vector<int>&nums,int index,int k){
        if(index==nums.size()-1)return nums[index];
        
        if(memo.find(index)!=memo.end())return memo[index];
        int next=INT_MIN;
        for(int i=index+1;i<=min(index+k,(int)nums.size()-1);i++)
            next=max(next,solve_memo(nums,i,k));
        memo[index]=nums[index]+next; 
        return memo[index];
    }
    int maxResult(vector<int>& nums, int k) {
        memo.clear();
        int n=nums.size();
        // return solve_memo(nums,0,k);     // O(n*k) using memoisation 
        
        deque<int>d;
        d.push_back(0);
        for(int i=1;i<n;i++){
            if(i-d.front()>k)d.pop_front();
            nums[i]=nums[i]+nums[d.front()];
            while(!d.empty() and nums[d.back()]<=nums[i])d.pop_back();
            d.push_back(i);
        }
        return nums[n-1];
    }
};
