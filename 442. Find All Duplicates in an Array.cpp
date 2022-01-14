class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int f[n+1];
        memset(f,0,sizeof(f));
        vector<int>ans;
        for(int i:nums){
            f[i]++;
            if(f[i]>1)ans.push_back(i);
        }
        return ans;
    }
};
