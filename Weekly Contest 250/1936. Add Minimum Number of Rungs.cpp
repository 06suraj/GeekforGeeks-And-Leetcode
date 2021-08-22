class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int h=0,ans=0;
        for(int i=0;i<rungs.size();i++){
            if(rungs[i]-h>dist)ans+=(rungs[i]-h)%dist?(rungs[i]-h)/dist:(rungs[i]-h)/dist-1;
            h=rungs[i];
        }
        return ans;
    }
};
