class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       int n=nums.size();
       long long prefix[n],ans=LLONG_MAX;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+nums[i];
        
        // 1. brute force solution which taken o(n^2)
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         {
        //             if(i==0 and prefix[j]>=k)ans=min(ans,j+1);
        //             else if(i and prefix[j]-prefix[i-1]>=k)ans=min(ans,j-i+1);
        //         }
        //     }
        // }
        // return (ans==INT_MAX?-1:ans);
        
        
        // 2. using deque for more explaination follow this link 
            // https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/751834/Intuition-for-Deque-questions-on-WHY-to-use-and-WHAT-to-store-in-deque-with-FULL-explanation
        deque<int>d; // it will maintain the minimum and maximum prefix  sum in o(1) time to evaluate to check whether a particular subarray will satisfy our needs or not
        d.push_back(0);
        if(prefix[0]>=k)ans=1;
        for(int i=1;i<n;i++){
            if(d.empty()){
                if(prefix[i]>=k)ans=min(ans,(long long)i+1);
                d.push_back(i);
            }
            else{
                if(prefix[i]>=k)ans=min(ans,(long long)i+1);
                cout<<d.front()<<" ";
                while(!d.empty() and prefix[i]-prefix[d.front()]>=k){
                    ans=min(ans,(long long)i-d.front());
                    // cout<<d.front()<<" "<<ans<<endl;
                    d.pop_front();
                }
                // if(!d.empty() and prefix[d.front()]>prefix[i]){
                //     while(!d.empty() and prefix[d.front()]>prefix[i])d.pop_front();
                //     d.push_front(i);
                // }
                // else{
                    while(!d.empty() and prefix[d.back()]>=prefix[i])d.pop_back();
                    d.push_back(i);
                // }
        
         }
        }
        return (ans==LLONG_MAX?-1:ans);
    }
};
