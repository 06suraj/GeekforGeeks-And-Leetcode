class Solution {
public:
    const int mod=1000000007;
    int memo[51][51][51];
    int solve(int m,int n,int maxMove,int startRow,int startColumn){
        if(startRow>=m or startRow<0 or startColumn>=n or startColumn<0)return 1;
        if(!maxMove)return 0;
        if(memo[startRow][startColumn][maxMove]!=-1)return (memo[startRow][startColumn][maxMove]%mod);
       long int left=solve(m,n,maxMove-1,startRow,startColumn-1);
       long int right=solve(m,n,maxMove-1,startRow,startColumn+1);
       long int up=solve(m,n,maxMove-1,startRow-1,startColumn);
       long int down=solve(m,n,maxMove-1,startRow+1,startColumn);
        long long ans=(left%mod+right%mod+up%mod+down%mod)%mod;
        return memo[startRow][startColumn][maxMove]=ans;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
       return solve(m,n,maxMove,startRow,startColumn); 
    }
};
