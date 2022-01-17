class Solution {
public:
    int solve(int index,vector<string>& words,vector<int>& score,int f[]){
        if(index>=words.size())return 0;
        
        int take=1,cost=0,ansTake=0,ansNotTake=0;
        for(int i=0;i<words[index].size();i++){
            if(!f[words[index][i]-'a']){
                take=0;
                for(int j=0;j<i;j++)f[words[index][j]-'a']++;
                break;
            }else {f[words[index][i]-'a']--;cost+=score[words[index][i]-'a'];}
        }
         //Take the current word
        if(take){
            ansTake=cost+solve(index+1,words,score,f);
            for(char i:words[index])f[i-'a']++;
        }
        //NOT Take the current word
        ansNotTake=solve(index+1,words,score,f);
        return max(ansTake,ansNotTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int f[26]={0};
        for(char i:letters)f[i-'a']++;
        return solve(0,words,score,f);
    }
};
