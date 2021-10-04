class Solution {
public:
    
   long long int memo[4][3][5001];
    int dirx[8]={2,2,-2,-2,1,1,-1,-1};
    int diry[8]={1,-1,1,-1,2,-2,2,-2};
    int mod=1000000007;
   long long solve_recur(vector<vector<int>>&keypad,int row,int col,int n){
       if(row<0 or row>=4 or col<0 or col>=3 or keypad[row][col]=='*' or keypad[row][col]=='#' or n<=0)return 0;
       
      if(n==1)return 1;
       
       long long cnt=0;
       for(int i=0;i<=7;i++){
           cnt+=solve_recur(keypad,row+dirx[i],col+diry[i],n-1);
       }
       return cnt;
       
   }
   
   long long solve_memo(vector<vector<int>>&keypad,int row,int col,int n){
       if(row<0 or row>=4 or col<0 or col>=3 or keypad[row][col]=='*' or keypad[row][col]=='#')return 0;
       
      if(n==1)return 1;
       
       if(memo[row][col][n]!=-1)return memo[row][col][n];
       long long cnt=0;
       
       for(int i=0;i<=7;i++){
           cnt=(cnt%mod+solve_memo(keypad,row+dirx[i],col+diry[i],n-1)%mod)%mod;
       }
       return memo[row][col][n]=cnt%mod;
       
   }

    int knightDialer(int n) {
        vector<vector<int>>keypad;
		int cnt=1;
		for(int i=0;i<3;i++){
		    vector<int>temp;
		    for(int j=0;j<3;j++)temp.push_back(cnt++);
		    keypad.push_back(temp);
		}
		keypad.push_back({'*',0,'#'});
	
		long long ans=0;
// 		for(int i=0;i<4;i++){
// 		    for(int j=0;j<3;j++)ans+=solve_recur(keypad,i,j,n);
// 		}

		memset(memo,-1,sizeof(memo));
		for(int i=0;i<4;i++){
		    for(int j=0;j<3;j++)ans+=(solve_memo(keypad,i,j,n))%mod;
		}
		
		
		return ans%mod;
    }
};
