class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,cnt=0,i1;
        string ans="";
        for(i1=0;i1<s.size() and i<spaces.size();){
            if(i1==spaces[i]+cnt){ans+=" ";i++;}
            else ans+=s[i1++];
        }
        while(i1<s.size())ans+=s[i1++];
        return ans;
    }
};
