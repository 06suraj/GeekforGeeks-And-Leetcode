class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>ma;
        ma[0]=1;
        int prefix=0,ans=0;
        for(int i:nums){
            prefix+=i;
            if(ma.find(prefix-k)!=ma.end())ans+=ma[prefix-k];
            ma[prefix]++;
        }
        return ans;
    }
};
