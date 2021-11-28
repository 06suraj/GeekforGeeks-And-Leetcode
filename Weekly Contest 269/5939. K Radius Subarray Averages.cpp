class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),i,centre=-1;
         vector<int>ans(n,-1);
        long long sum=0;
        for(i=0;i<2*k+1 and i<n;i++){
            if(i==k)centre=i;
            sum+=nums[i];
        }
        if(i!=2*k+1)return ans;
        else{
            int j=i;
            i=0;
            ans[centre]=sum/(2*k+1);;
            while(j<n){
                sum=sum-nums[i]+nums[j];
                centre++;
                ans[centre]=sum/(2*k+1);
                i++,j++;
            }
            return ans;
        }
    }
};
