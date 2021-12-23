class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        pair<int,int>p[s.size()];
        for(int i=0;i<s.size();i++){
            p[i].first=indices[i];
            p[i].second=s[i];
        }
        sort(p,p+s.size());
        string ans="";
        for(pair<int,int>a:p)ans+=a.second;
        return ans;
    }
};
