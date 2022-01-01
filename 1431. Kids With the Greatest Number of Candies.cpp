class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxi=*max_element(candies.begin(), candies. end()) ;
        for(int i: candies) {
            if(i+extraCandies>=maxi) ans. push_back(1) ;
            else ans. push_back(0) ;}
        return ans;
    }
};
