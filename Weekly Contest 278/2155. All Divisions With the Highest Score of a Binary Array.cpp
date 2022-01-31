class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0),suffix(n,0),ans;
        prefix[0]=(nums[0]==0?1:0);
        for(int i=1;i<n;i++){
            if(nums[i]==0)prefix[i]=1+prefix[i-1];
            else prefix[i]=prefix[i-1];
        }
        suffix[n-1]=(nums[n-1]==1?1:0);
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1)suffix[i]=1+suffix[i+1];
            else suffix[i]=suffix[i+1];
        }
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(i==0)cnt=max(cnt,suffix[0]);
            else if(i==n)cnt=max(cnt,prefix[i-1]);
            else{
                cnt=max(cnt,prefix[i-1]+suffix[i]);
            }
        }
        for(int i=0;i<=n;i++){
            if(i==0){
                if(suffix[0]==cnt)ans.push_back(0);
            }
            else if(i==n){
                if(prefix[i-1]==cnt)ans.push_back(i);
            }
            else{
                if(prefix[i-1]+suffix[i]==cnt)ans.push_back(i);
            }
        }

        return ans;
        
    }
};
