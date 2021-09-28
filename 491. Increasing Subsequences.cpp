class Solution {
public:
    void solve(int index,int prev,int n,vector<int>&nums,vector<int>&temp,set<vector<int>>&unique)
    {
        if(index>=n){
            if(temp.size()>=2)unique.insert(temp);
            return ;
        }
        
        if(temp.size()>=2)unique.insert(temp);
        
        if(prev==-1 or nums[prev]<=nums[index])
            {
                temp.push_back(nums[index]);
                solve(index+1,index,n,nums,temp,unique);
                temp.pop_back();
                solve(index+1,prev,n,nums,temp,unique);
            }
            else solve(index+1,prev,n,nums,temp,unique);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>unique;
        int index=0,n=nums.size(),prev=-1;
        vector<int>temp;
        solve(index,prev,n,nums,temp,unique);
        for(auto i:unique){
            ans.push_back(i);
        }
        return ans;
    }
};
