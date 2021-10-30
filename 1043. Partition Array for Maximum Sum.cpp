class Solution {
public:
    
    //simple memoisastion version with T.C O(N*k)
    
    int memo[500];
    int solve(vector<int>&arr,int start,int k){
        if(start==arr.size())return 0;
        if(memo[start]!=-1)return memo[start];
        int ans=0,maxi=0;
        for(int i=start;i<min(start+k,(int)arr.size());i++){
            int len=i-start+1;
            maxi=max(maxi,arr[i]);
            ans=max(ans,maxi*len+solve(arr,i+1,k));
        }
        return memo[start]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(arr,0,k);
    }
};
