class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int>dry;
        map<int,int>flood;
        vector<int>ans;
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                dry.insert(i);
                ans.push_back(1);
            }else{
                if(flood.find(rains[i])!=flood.end()){
                    if(dry.empty())return {};
                    auto it=dry.lower_bound(flood[rains[i]]);
                    if(it==dry.end())return {};
                    ans[*it]=rains[i];
                    dry.erase(*it);
                }
                    flood[rains[i]]=i;
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
