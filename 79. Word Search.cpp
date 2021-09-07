class Solution {
public:
    bool solve(vector<vector<char>>& board,string word,vector<vector<int>>&vis,string temp,int i,int j,int row,int col){
        if(temp==word)return 1;
        if(temp.size()>=word.size())return 0;
        if(i>=row or j>=col or i<0 or j<0 or vis[i][j]==1)return 0;
        if(word[temp.size()]!=board[i][j])return 0;
        vis[i][j]=1;
       if(solve(board,word,vis,temp+board[i][j],i,j+1,row,col))return 1;
       if(solve(board,word,vis,temp+board[i][j],i,j-1,row,col))return 1;
       if(solve(board,word,vis,temp+board[i][j],i+1,j,row,col))return 1;
       if(solve(board,word,vis,temp+board[i][j],i-1,j,row,col))return 1;
      vis[i][j]=0;
        return 0;
    }
    
    bool checkAlphabets(vector<vector<char>>& board, string word){
        int f[126]={0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)f[board[i][j]-'A']++;
        }
        for(int i=0;i<word.size();i++){
            if(f[word[i]-'A']==0)return 0;
        }
        return 1;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
//         below two cases handle the base case and slightly optimise the code
        if(word.empty() || board.empty() || board[0].empty()) 
            return false; 
        
        if(!checkAlphabets(board, word)) {
            return false;
        }
        
        int n=board.size(),m=board[0].size();

//         below is the main checking using backtracking
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               string temp="";
                vector<vector<int>> vis( n , vector<int> (m, 0));
               if(solve(board,word,vis,temp,i,j,n,m))return 1;
           }
       }
        return 0;
    }
};
