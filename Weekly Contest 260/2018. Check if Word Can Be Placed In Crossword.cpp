class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        string s="";
        
        // HORIZONTAL TRAVERSAL
        for(int i=0;i<n;i++){
            int prev=-1,len;
            for(int j=0;j<m;j++){
                  // cout<<s<<" ";
                if(board[i][j]=='#'){
                    if(prev==-1)
                    {
                        len=j+prev+1;
                        if(len==word.size())
                        {
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                                // cout<<s<<" ";
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                  if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        prev=j;
                        s.clear();
                    }else{
                         // cout<<s<<" ";
                        len=j-prev-1;
                        if(len==word.size())
                        {
                            
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                               // cout<<s<<" ";
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        prev=j;
                        s.clear();
                    }
                }else if(board[i][j]>='a' and board[i][j]<='z')
                    s+=board[i][j];
                else s+='@';
            
            }
                        if(prev==-1)
                        len=m+prev+1;
                         else len=m-prev-1;
                        if(len==word.size())
                        {
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                  if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        // prev=j;
                        s.clear();
            
        }
        s.clear();
        // return 0;
        
        
        // VERTICAL TRAVERSAL
        
        for(int i=0;i<m;i++){
            int prev=-1,len;
            for(int j=0;j<n;j++){
                if(board[j][i]=='#'){
                    if(prev==-1)
                    {
                        len=j+prev+1;
                        if(len==word.size())
                        {
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        prev=j;
                        s.clear();
                    }else{
                        len=j-prev-1;
                        if(len==word.size())
                        {
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        prev=j;
                        s.clear();
                    }
                }else if(board[j][i]>='a' and board[j][i]<='z')
                    s+=board[j][i];
                else s+='@';
            }
                       if(prev==-1)len=n+prev+1;
                        else
                        len=n-prev-1;
                        if(len==word.size())
                        {
                            if(s.empty())return 1;
                            else if(s.size()<=word.size())
                            {
                                int flag=0;
                                for(int i1=0;i1<s.size();i1++){
                                    if(s[i1]!=word[i1] and s[i1]!='@')
                                        flag=1;
                                }
                                if(flag==0)return 1;
                                int j1=0;
                                for(int i1=s.size()-1;i1>=0;i1--){
                                    if(s[i1]!=word[j1++] and s[i1]!='@')
                                        flag++;
                                }
                                if(flag<=1)return 1;
                                
                            }
                        }
                        // prev=j;
                        s.clear();
            
        }
        
        
        return 0;
    }
};
