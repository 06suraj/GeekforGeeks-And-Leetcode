class Solution {
public:
    //isSubstring taken from https://www.geeksforgeeks.org/check-string-substring-another/
    int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(int i=0;i<patterns.size();i++){
            if(isSubstring(patterns[i],word)!=-1)cnt++;
        }
               return cnt;
    }
};
