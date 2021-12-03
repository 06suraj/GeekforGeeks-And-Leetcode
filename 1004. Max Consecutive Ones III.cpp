class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      deque<int>d;
      int cnt=0,ans=INT_MIN;
      for(int i=0;i<nums.size();i++){
          if(nums[i]==0){
              d.push_back(nums[i]);
              cnt++;
              if(cnt>k){
                  ans=max(ans,(int)d.size()-1);
                  while(!d.empty() and d.front()!=0)d.pop_front();
                  d.pop_front();
                  cnt--;
              }
          }else d.push_back(nums[i]);
      }
       ans=max(ans,(int)d.size());
        return ans;
    }
};
