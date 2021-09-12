class Solution {
public:
    // we will use simple backtracking to generate all possible non overlappig subsequence and then find maximum product(BRUTE FORCE)
    
    int maxi=0;
    bool ispal(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    
    void solve(string &s,string &s1,string &s2,int i){
        if(i>=s.size()){
            if(ispal(s1) and ispal(s2)){
                int l=s1.size(),r=s2.size();
                maxi=max(maxi,l*r);
            }
            return ;
        }
        s1.push_back(s[i]);
        solve(s,s1,s2,i+1);
        s1.pop_back();
        
        s2.push_back(s[i]);
        solve(s,s1,s2,i+1);
        s2.pop_back();
        
        solve(s,s1,s2,i+1);
    }
    
    int maxProduct(string s) {
        string s1="",s2="";
        solve(s,s1,s2,0);
        return maxi;
    }
};
