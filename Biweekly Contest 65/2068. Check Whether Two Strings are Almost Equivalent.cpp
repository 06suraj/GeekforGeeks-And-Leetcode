class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
       int f[26]={0},f1[26]={0};
       for(char i:word1)f[i-'a']++;
       for(char i:word2)f1[i-'a']++;
        for(int i=0;i<26;i++){
            if(abs(f[i]-f1[i])>3)return 0;
        }
        return 1;
    }
};
