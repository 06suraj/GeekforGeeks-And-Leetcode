class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,s=0;
        
        map<int,int>cnt;
        for(int i=0;i<n;i++){
            s=(s+nums[i])%k;
            if(s<0)s+=k; // to handle negative
            if(cnt.find(s)!=cnt.end())ans+=cnt[s];
            cnt[s]++;
        }
        
        return ans+cnt[0];
    }
};
