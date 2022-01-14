class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
      vector<pair<int,int>>grow;
       int ans=0,curr=0;
        for(int i=0;i<plantTime.size();i++){
            grow.push_back({growTime[i],plantTime[i]});
        }
        sort(grow.begin(),grow.end(),greater<pair<int,int>>());
        for(int i=0;i<plantTime.size();i++){
            curr=curr+grow[i].second;
            ans=max(ans,curr+grow[i].first+1);
        }
        return ans-1;
            
    }
};
