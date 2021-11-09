class Solution {
public:
    int minimizedMaximum(int n1, vector<int>& nums) {
        int lb=1,ub=*max_element(nums.begin(),nums.end()),n=nums.size(),ans;
       while(lb<=ub){
           int mid=lb+(ub-lb)/2,s=0;
           for(int i=0;i<n;i++){
               if(nums[i]%mid)s+=nums[i]/mid+1;
               else s+=nums[i]/mid;
           }
           if(s<=n1)ub=mid-1,ans=mid;
           else lb=mid+1;
       }
        return ans;
    }
};
