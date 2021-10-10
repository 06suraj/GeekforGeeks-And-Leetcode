class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int>temp;
        vector<int>ans;
        map<int,int>ma;
        for(int i:nums1)ma[i]++;
        for(int i:nums2){
            if(ma.find(i)!=ma.end())temp.insert(i);
            // ma[i]++;
            
        }
        for(int i:nums2){
            ma[i]++;
            
        }
        for(int i:nums3){
            if(ma.find(i)!=ma.end())temp.insert(i);
        }
        for(int i:temp)ans.push_back(i);
        return ans;
    }
};
