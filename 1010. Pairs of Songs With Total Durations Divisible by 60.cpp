class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>ma;
        int ans=0;
        for(int i:time){
            int rem=i%60;
            if(!rem){
                if(ma.find(rem)!=ma.end())ans+=ma[rem];
                ma[rem]++;
            }else{
                  if(ma.find(60-rem)!=ma.end())ans+=ma[60-rem];
                ma[rem]++;
            }
        }
        return ans;
    }
};
