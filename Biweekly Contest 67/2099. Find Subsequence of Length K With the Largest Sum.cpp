class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        set<pair<int,int>>s;
        pair<int,int>p[nums.size()];
        for(int i=0;i<nums.size();i++)p[i].first=nums[i],p[i].second=i;
        sort(p,p+n);
        reverse(p,p+n);
        for(int i=0;i<k;i++){
            s.insert({p[i].second,p[i].first});
        }
        for(auto i:s){
            ans.push_back(i.second);
        }
        return ans;
    }
};
