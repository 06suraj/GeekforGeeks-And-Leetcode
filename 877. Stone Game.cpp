class Solution {
public:
    int memo[501][2];
    int solve(vector<int>&piles,int turn,int index,int last){
        if(index>=piles.size() or last<0)return 0;
        if(memo[index][turn]!=-1)return memo[index][turn];
        int first,last1;
        if(turn){
             first=piles[index]+solve(piles,turn-1,index+1,last);
             last1=piles[last]+solve(piles,turn-1,index,last-1);
            
        }else{
             first=piles[index]+solve(piles,turn+1,index+1,last);
            last1=piles[last]+solve(piles,turn+1,index,last-1);
        }
        memo[index][turn]=max(first,last1);
        return memo[index][turn];
        
    }
    bool stoneGame(vector<int>& piles) {
        memset(memo,-1,sizeof(memo));
        solve(piles,0,0,piles.size()-1);
        if(memo[0][0]>memo[0][1])return 1;
        else return 0;
    }
};
