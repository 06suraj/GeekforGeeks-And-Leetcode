class Solution {
public:
    bool pal(string&s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            if(pal(s))return s;
        }
        return "";
    }
};
