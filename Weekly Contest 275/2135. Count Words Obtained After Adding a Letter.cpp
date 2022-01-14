class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string,int>target;
        unordered_set<string>check;
        int ans=0;
        for(string s:targetWords){
            sort(s.begin(),s.end());
            target[s]++;
        }
        for(string s:startWords){
            int f[126]={0};
            for(char i:s)f[i]++;
            for(char i='a';i<='z';i++){
                if(f[i]>0)continue;
                string temp="";
                temp+=s;
                temp+=i;
                if(check.find(temp)!=check.end())continue;
                sort(temp.begin(),temp.end());
                if(target.find(temp)!=target.end()){
                    ans+=target[temp];
                    target[temp]=0;
                }
                check.insert(temp);
            }
        }
        return ans;
    }
};
