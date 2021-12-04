class Solution {
public:
    // just partition it at each and every node  sot that all nodes from l to i are in left subtree and remaining in right subtree
    int memo[41][41];
    int solve(int l,int h,vector<int>&arr){
        if(l==h){
            return 0; // it will be lead node so the smallest possible sum for leaf node is 0 
        }
        if(memo[l][h]!=-1)return memo[l][h];
        int currSum=INT_MAX;
        for(int k=l;k<h;k++) // parition at every node from l to h
        {
            int leftSum=solve(l,k,arr);
            int rightSum=solve(k+1,h,arr);
            int maxLeftLeaf=INT_MIN,maxRightLeaf=INT_MIN;
            for(int i=l;i<=k;i++)maxLeftLeaf=max(maxLeftLeaf,arr[i]);
            for(int i=l+1;i<=h;i++)maxRightLeaf=max(maxRightLeaf,arr[i]);
            currSum=min(currSum,leftSum+rightSum+maxLeftLeaf*maxRightLeaf);
        }
        return memo[l][h]=currSum;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(memo,-1,sizeof(memo));
        return solve(0,arr.size()-1,arr);
    }
};
