class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int j=1,cnt=1,n=prices.size();
        long long ans=0;
        while(j<n){
            if(prices[j]+1==prices[j-1])j++,cnt++;
            else{
                ans+=((cnt)*(long long)(cnt+1))/2;
                cnt=1;
                j++;
            }
        }
        ans+=((cnt)*(long long)(cnt+1))/2;
        return ans;
        
    }
};
