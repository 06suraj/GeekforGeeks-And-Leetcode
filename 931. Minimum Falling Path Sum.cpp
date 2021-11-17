class Solution {
public:
    int memo[101][101];
    int solve(vector<vector<int>>&matrix,int row,int col){
        if(row>=matrix.size())return 0;
        if(memo[row][col]!=-1)return memo[row][col];
            int left=INT_MAX,right=INT_MAX,bottom=INT_MAX;
            if(col-1>=0)left=solve(matrix,row+1,col-1);
            if(col+1<matrix.size())right=solve(matrix,row+1,col+1);
               bottom=solve(matrix,row+1,col);
         return memo[row][col]=matrix[row][col]+min(left,min(right,bottom));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(memo,-1,sizeof(memo));
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            int left=INT_MAX,right=INT_MAX,bottom=INT_MAX;
            if(i-1>=0)left=solve(matrix,1,i-1);
            if(i+1<matrix.size())right=solve(matrix,1,i+1);
            bottom=solve(matrix,1,i);
            ans=min(ans,matrix[0][i]+min(left,min(right,bottom)));
            
        }
        return ans;
    }
};
