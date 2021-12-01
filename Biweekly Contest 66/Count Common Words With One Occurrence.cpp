class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int>ma,ma1;
        for(string s:words1)ma[s]++;
        for(string s:words2){
            ma1[s]++;
        }
        int cnt=0;
        for(auto i:ma){
            if(i.second==1 and ma1.find(i.first)!=ma.end() and ma1[i.first]==1)cnt++;
        }
        return cnt;
    }
};
