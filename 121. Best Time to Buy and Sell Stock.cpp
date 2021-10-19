class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxi=arr[0],mini=arr[0],ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>maxi)
               maxi=arr[i];
            else{
                ans=max(ans,maxi-mini);
                if(arr[i]<mini)mini=arr[i];
                maxi=arr[i];
            }
        }
        ans=max(ans,maxi-mini);
        return ans;
    }
};
