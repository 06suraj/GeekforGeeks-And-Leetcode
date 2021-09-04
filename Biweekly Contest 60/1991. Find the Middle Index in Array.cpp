class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=0,s1=0;
            for(int j=0;j<i;j++)s+=nums[j];
            for(int j=i+1;j<n;j++)s1+=nums[j];
            if(s==s1)return i;
        }
        return -1;
    }
};
