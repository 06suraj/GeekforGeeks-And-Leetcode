class Solution {
public:
    int memo[366];
    int solve(vector<int>& days, vector<int>& costs,int index){
        if(index==days.size())return 0;
        if(memo[index]!=-1)return memo[index];
        int day1=costs[0],day7=costs[1],day30=costs[2];
        for(int i=index+1;i<days.size();i++){
            if(days[i]>=days[index]+7){
                day7+=solve(days,costs,i);
                break;
            }
        }
         for(int i=index+1;i<days.size();i++){
            if(days[i]>=days[index]+30){
                day30+=solve(days,costs,i);
                break;
            }
        }
        day1+=solve(days,costs,index+1);
        return memo[index]=min({day1,day7,day30});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memo,-1,sizeof(memo));
        return solve(days,costs,0);
    }
};
