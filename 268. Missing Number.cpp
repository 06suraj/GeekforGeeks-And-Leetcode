class Solution {
public:
    
    // O(N) RUNNING TIME AND O(1) SPACE
    
    int missingNumber(vector<int>& nums) {
        int s=nums.size()*(nums.size()+1)/2;
        for(int i:nums)s-=i;
        return  s;
    }
};
