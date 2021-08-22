class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int f[26]={0};
        for(int i=0;i<brokenLetters.size();i++)f[brokenLetters[i]-'a']++;
        int cnt=0,flag=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==32){
                if(flag==0)cnt++;
                flag=0;
            }
            else {
                if(f[text[i]-'a'])flag=1;
            }
            
        }
        if(flag==0)cnt++;
        return cnt;
    }
};
