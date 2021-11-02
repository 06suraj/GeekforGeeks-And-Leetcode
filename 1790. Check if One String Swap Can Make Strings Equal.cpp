class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff=0;
        vector<int>pos;
        for(int i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i]!=s2[i]){diff++;pos.push_back(i);}
        }
        if(diff>2 or diff==1)return 0;
        else if(diff==0)return 1;
        else{
            if(s1[pos[0]]==s2[pos[1]] and s1[pos[1]]==s2[pos[0]])return 1;
            else return 0;
        }
    }
};
