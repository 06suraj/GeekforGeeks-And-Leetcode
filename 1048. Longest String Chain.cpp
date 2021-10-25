class Solution {
public:
    int dp[1001];
    static bool cmp(string&a , string&b){
        return a.size()<b.size();
    }
    bool check(string &a,string&b){
        if(a.size()==b.size() or b.size()-a.size()>1)return 0;
           for(int i=0;i<b.size();i++){
               string temp=b.substr(0,i)+b.substr(i+1,b.size()-i-1);
               if(temp==a)return 1;
           }
            return 0;
        
    }
    int memo(int start,vector<string>&words){
        if(dp[start]!=-1)return dp[start];
        int ans=1;
        for(int i=start+1;i<words.size();i++){
            if(check(words[start],words[i]))ans=max(ans,1+memo(i,words));
        }
        dp[start]=ans;
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),cmp);
        int ans=1,n=words.size();
        for(int i=0;i<n;i++)ans=max(ans,memo(i,words));
        return ans;
    }
};
