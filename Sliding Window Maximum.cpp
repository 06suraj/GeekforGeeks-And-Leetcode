class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        int i;
        for( i=0;i<k;i++){
            if(d.empty())d.push_front(i);
            else{
                if(nums[i]>nums[d.front()])
                    d.push_front(i);
                else {
                    while(!d.empty() and nums[d.back()]<nums[i])d.pop_back();
                    d.push_back(i);
                }
            }
        }
        vector<int>ans;
        ans.push_back(nums[d.front()]);
        int n=nums.size();
        while(i<n){
            while(!d.empty() and d.front()<i-k+1)d.pop_front();
            if(!d.empty() and nums[i]>nums[d.front()]){d.push_front(i);ans.push_back(nums[i]);}
            else {
    
                while(!d.empty() and nums[d.back()]<nums[i])d.pop_back();
                    d.push_back(i);
                 ans.push_back(nums[d.front()]);
            }
            i++;
        }
        return ans;
        
    }
};
