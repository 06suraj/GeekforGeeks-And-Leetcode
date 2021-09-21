class Solution {
public:

    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size(),ans=0,maxi;
        int next[n],previous[n];next[n-1]=-1;maxi=nums[n-1];
        previous[0]=-1;
       for(int i=n-2;i>=0;i--){
           if(nums[i]>=maxi){
               next[i]=1;
           }else next[i]=-1,maxi=nums[i];
       }
        maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=maxi)
            {
                previous[i]=1;
            }else previous[i]=-1,maxi=nums[i];
        
        }
        for(int i=1;i<n-1;i++){
            if(previous[i]==-1 and next[i]==-1)ans+=2;
            else if(nums[i-1]<nums[i] and nums[i]<nums[i+1])ans++;
        }
        return ans;
           
    }
};
