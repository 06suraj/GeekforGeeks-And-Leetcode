class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>ma;
        for(int i:nums)ma[i]++;
        while(ma.find(original)!=ma.end())original*=2;
        return original;
    }
};
