class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),ans=INT_MAX;
        vector<long int>prefix(n,0),suffix(n,0);
        prefix[0]=nums[0],suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)suffix[i]=suffix[i+1]+nums[i];
        map<int,int>ma;
        for(int i=0;i<n;i++){
            if(nums[i]==x)ans=1;
            if(prefix[i]==x)ans=min(ans,i+1);
        }
        for(int i=n-1;i>=0;i--){
            if(suffix[i]==x)ans=min(ans,n-i);
        }
        ma.clear();
        for(int i=n-1;i>=0;i--)ma[suffix[i]]=i;
        int i=0;
        while(i<n){
            if(ma.find(x-prefix[i])!=ma.end() and ma[x-prefix[i]]>i){
                ans=min(ans,i+1+n-ma[x-prefix[i]]);
            }
            i++;
        }
        return (ans==INT_MAX?-1:ans);
        
        
    }
};
