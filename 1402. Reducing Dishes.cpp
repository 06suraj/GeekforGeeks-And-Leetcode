class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(),satisfaction.rend());
        int ans=0,s=0;
        for(int i=0;i<satisfaction.size();i++){
            if(s+satisfaction[i]<0)break;
            else ans+=s+satisfaction[i],s+=satisfaction[i];
        }
        return ans;
    }
    
};
