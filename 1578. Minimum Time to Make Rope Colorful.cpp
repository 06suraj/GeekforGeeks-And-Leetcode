class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=0,ans=0,n=colors.size(),mini=INT_MIN,sum=0;
        while(j<n){
            if(colors[j]==colors[i]){mini=max(mini,neededTime[j]);sum+=neededTime[j];j++;}
            else{
                if(j-i>1){
                    ans+=sum-mini;
                }
                mini=sum=neededTime[j];
                i=j;
                j++;
            }
        }
        if(j-i>1){
                ans+=sum-mini;
                }
        return ans;
        
    }
};
