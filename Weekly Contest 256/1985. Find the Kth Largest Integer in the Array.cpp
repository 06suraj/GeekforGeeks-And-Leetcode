class Solution {
public:
 static   bool cmp(string a, string b)
    {
    if(a.size()!=b.size())return a.size()<b.size();
     else return lexicographical_compare(a.begin(), a.end(),b.begin(), b.end());
}
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        // for(auto i:nums)cout<<i<<" ";
         reverse(nums.begin(),nums.end());
       // for(auto i:nums)cout<<i<<" ";
        return nums[k-1];
    }
};
