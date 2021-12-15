class Solution {
public:
    bool isvalid(vector<vector<int>>&grid,int row,int col){
        if(row<0 or row>=grid.size() or col<0 or col>=grid[0].size())return 0;
        return 1;
    }
    int find(vector<vector<int>>&grid,int row,int col){
        if(row==grid.size())return col;
        if(isvalid(grid,row,col)){
            if(grid[row][col]==1){
                if(isvalid(grid,row,col+1) and grid[row][col+1]==1)
                    return find(grid,row+1,col+1);
            }else {
                if(isvalid(grid,row,col-1) and grid[row][col-1]==-1)
                    return find(grid,row+1,col-1);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int i=0;i<grid[0].size();i++){
            int x=find(grid,0,i);
            ans.push_back(x);
        }
        return ans;
    }
};
