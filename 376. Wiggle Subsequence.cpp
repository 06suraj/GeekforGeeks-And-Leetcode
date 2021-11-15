class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
           int ans=1,flag=0,start=1;
           while(start<nums.size() and nums[start]==nums[0])start++;
         if(start==nums.size())return 1;
            if(nums[start]>nums[start-1])flag=1;
            else flag=0;
          for(int i=start;i<nums.size();i++){
              if(flag){
                  if(nums[i]<nums[i-1]) ans++,flag=0;
              }else{
                  if(nums[i]>nums[i-1])ans++,flag=1;
              }
          }
        return (nums.size()>=2?ans+1:ans);
    }
};
