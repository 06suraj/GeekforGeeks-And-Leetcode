class Solution {
public:
 int dp[2001][2001];
bool  ispal(string &s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])return 0;
        i++;
        j--;
    }
    return 1;
}
int solve(string &s,int i,int j){
    if(i>j) return 0;  // string is empty
    
    if(ispal(s,i,j)) return dp[i][j]=0;  // if string is palindrome then no need to paritition it
     
    if(dp[i][j]!=-1)return dp[i][j]; // if the subproblems(i....j) is previously solved
    dp[i][j]=INT_MAX;  // return the optimal one
    int cnt=INT_MAX;
    for(int k=i;k<j;k++){
        /*An Optimization: We will make the partition only if the string till the partition 
		(till Kth position) is a valid palindrome. Because the question states that all 
		partition must be a valid palindrome. If we dont check this, we will have to 
		perform recursion on the left subproblem too (solve(str, i, k)) and	we will waste 
		a lot of time on subproblems that is not required. Without this the code will give
		correct answer but TLE on big test cases. */
         if(ispal(s, i, k))
            cnt = min(cnt,1+solve(s,k+1,j));  
        
    }
    return dp[i][j]=cnt;
}
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return(solve(s,0,s.size()-1));
    }
};
