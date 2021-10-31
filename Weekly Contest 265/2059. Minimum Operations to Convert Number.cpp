class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int>q;
        int ans=0;
        bool vis[10000]={0};
        q.push(start);
        while(!q.empty()){
            int si=q.size();
            while(si--){
                int first=q.front();
                q.pop();
                if(first==goal)return ans;
                if(first>=0 and first<=1000 and vis[first]==0 ){
                    vis[first]=1;
                    for(int i=0;i<nums.size();i++){
                        q.push(first+nums[i]),q.push(first-nums[i]),q.push(first^nums[i]);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
