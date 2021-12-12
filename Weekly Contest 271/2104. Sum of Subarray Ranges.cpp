class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long s=0,maxi=LLONG_MIN,mini=LLONG_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=nums[i],mini=nums[i];
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,(long long)nums[j]);
                mini=min(mini,(long long)nums[j]);
                s+=maxi-mini;
            }
        }
        return s;
    }
};
