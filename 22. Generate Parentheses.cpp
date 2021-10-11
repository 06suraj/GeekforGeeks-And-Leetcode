class Solution {
public:
   set<string>s;
    void solve(int n,int opening,int closing,string temp){
        if(temp.size()==2*n){
            s.insert(temp);
            return ;
        }
        if(opening<closing)return ;
        
        if(opening<n){
         temp.push_back('(');
         solve(n,opening+1,closing,temp);
         temp.pop_back();
        }
        
        if(opening){
         temp.push_back(')');
         solve(n,opening,closing+1,temp);
         temp.pop_back();
        }
}
    
    vector<string> generateParenthesis(int n) {
        s.clear();
        string temp="";
        int o=0,c=0;
        solve(n,o,c,temp);
        vector<string>ans;
        for(string s1:s)ans.push_back(s1);
        return ans;
    }
};
