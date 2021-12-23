#define mod 1000000007
class Solution {
public:
    int memo[101][201];
  
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<0)return 0;
        else if(start==finish){
            if(memo[start][fuel]!=-1)return memo[start][fuel];
          long long   int cnt=1;
            for(int i=0;i<locations.size();i++){
            if(start!=i)cnt=cnt%mod+(solve(locations,i,finish,fuel-abs(locations[i]-locations[start])))%mod;
          }
            return memo[start][fuel]=cnt%mod;
        }
         if(memo[start][fuel]!=-1)return memo[start][fuel];
        long long int cnt=0;
        for(int i=0;i<locations.size();i++){
            if(start!=i)cnt=cnt%mod+(solve(locations,i,finish,fuel-abs(locations[i]-locations[start])))%mod;
        }
       return memo[start][fuel]=cnt%mod;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(memo,-1,sizeof(memo));
        return solve(locations,start,finish,fuel);
    }
};
