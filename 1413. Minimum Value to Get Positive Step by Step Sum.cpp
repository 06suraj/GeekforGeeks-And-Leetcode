class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int l=1,r=0,ans=0;
        
        // 1. WE SEARCH FOR EACH INTEGER BETWEEN 1  TO SUM(ABS(NUMS)) USING BINARY SEARCH;
        for(int i:nums)r+=abs(i);
        while(l<=r){
            int mid=l+(r-l)/2,s=mid,flag=0;
            for(int i:nums){
                s+=i;
                if(s<=0)flag=1;
            }
            if(flag)l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }
        
        // 2. HERE WE SIMPLY CALCULATE THE MINIMUM AT EVERY INDEX USING PREFIX SUM
        int prefix=0,mini=0;
        for(int i:nums){
            prefix+=i;
            mini=min(mini,prefix);
        }
        return abs(mini)+1;
    }
};
