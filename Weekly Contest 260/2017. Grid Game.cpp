class Solution {
public:
    long long gridGame(vector<vector<int>>& mat) {
     int m=mat[0].size();
    long long ans=LLONG_MAX,s=0,prefix=0;
	 for(int i=0;i<2;i++){
	     for(int j=0;j<m;j++)mat[i][j];
	 }
	for(int i=0;i<m;i++)s+=mat[0][i];
	 for(int i=0;i<m;i++){
	     ans=min(ans,max(s-mat[0][i],prefix));
	     prefix+=mat[1][i];
	     s-=mat[0][i];
	 }
        return ans;
	
    }
};
