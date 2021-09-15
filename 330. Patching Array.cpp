class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
     long   int maxreach=0,ans=0,i=0;
       while(maxreach<n){
           if(i==nums.size()){
               maxreach+=maxreach+1;
               ans++;
           }
           else if(nums[i]<=maxreach+1)maxreach+=nums[i++];
           else {maxreach+=maxreach+1;ans++;}
       }
        return ans;
        
       }
};
