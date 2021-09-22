class Solution {
public:
    int memo[301][301];
    
    int solve_recur(vector<vector<char>>& matrix,int i,int j,int maxi){
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size() or matrix[i][j]=='0')return 0;
        return min(solve_recur(matrix,i+1,j,maxi),min(solve_recur(matrix,i+1,j+1,maxi),solve_recur(matrix,i,j+1,maxi)))+1;
       
    }
    
    int solve_memo(vector<vector<char>>& matrix,int i,int j){
         if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size() or matrix[i][j]=='0')return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        else return memo[i][j]=min(solve_memo(matrix,i+1,j),min(solve_memo(matrix,i+1,j+1),solve_memo(matrix,i,j+1)))+1;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
       int ans_recur=0,n=matrix.size(),m=matrix[0].size();
     
        //1 . BELOW SOLUTION IS JUST A RECURRENCE COLUTION WHICH WILL GIVE TLE
        
       /*for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]=='1')
                   ans_recur=max(ans_recur,solve_recur(matrix,i,j,ans_recur));
           }
       }*/
        // return ans_recur*ans_recur;
        
        //2. BELOW IS THE MEMOISED VERSION OF ABOVE RECURRENCE SOLUTION
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                    ans_recur=max(ans_recur,solve_memo(matrix,i,j));
            }
        }
        return ans_recur*ans_recur;
    }
};
