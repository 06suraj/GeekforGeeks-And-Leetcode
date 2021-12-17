class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1,cnt=0;
       while(s[j]==' ')j--;
        while(j>=0 and s[j]!=' '){j--,cnt++;}
        return cnt;
    }
};
