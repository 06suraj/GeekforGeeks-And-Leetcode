class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>ma;
        for(int i:nums)ma[i]++;
        int ans=0;
        for(auto i:ma)ans+=(i.second)*(i.second-1)/2;
        return ans;
    }
};
