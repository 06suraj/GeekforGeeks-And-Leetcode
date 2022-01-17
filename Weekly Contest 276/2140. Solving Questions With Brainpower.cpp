class Solution {
public:
    long long memo[100001];
    long long solve(int index,vector<vector<int>>& questions){
        if(index>=questions.size())return 0;
        if(memo[index]!=-1)return memo[index];
        long long s=0,s1=0;
        s=questions[index][0]+solve(index+questions[index][1]+1,questions);
        s1=solve(index+1,questions);
        return memo[index]=max(s,s1);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(memo,-1,sizeof(memo));
        return solve(0,questions);
    }
};
