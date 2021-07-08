class Solution{
public:
int dp[101][101];
int solve(int arr[],int i,int j)  // MEMEOIZED VERSION
{

    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j]; // check if the subproblems is previously solve or not
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)dp[i][j]=min(dp[i][j],solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    return dp[i][j];
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return(solve(arr,1,N-1));
    }
};
