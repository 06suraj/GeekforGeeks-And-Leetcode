class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>row,col;
        int n=matrix.size(),m=matrix[0].size();
        
        // O(M+N) SPACE SOLUTION
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)row.insert(i),col.insert(j);
            }
        }
        
//         for(int i:row){
//             for(int j=0;j<m;j++)matrix[i][j]=0;
//         }
        
//         for(int j:col)
//         {
//             for(int i=0;i<n;i++)matrix[i][j]=0;
//         }
        
        // O(1) SPACE SOLUTION
        int flag1=0,flag2=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)flag1=1;
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0)flag2=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
               
                if(matrix[i][j]==0)matrix[i][0]=0,matrix[0][j]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 or matrix[0][j]==0)matrix[i][j]=0;
            }
        }
       
        if(flag1){
            for(int i=0;i<n;i++)matrix[i][0]=0;
        }
        if(flag2){
            for(int j=0;j<m;j++)matrix[0][j]=0;
        }
       
    }
};
