class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size()-1,ans=0,cnt=0;
        for(int i=0;i<n;i++){
            while(m>=0){
                if(grid[i][m]>=0)break;
                else cnt++,m--;
            }
            ans+=cnt;
        }
        return ans;
    }
};
