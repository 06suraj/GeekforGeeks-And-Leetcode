class Solution {
public:
    bool possible(int n,vector<int>&batteries,long long threshold){
        long long s=0;
        for(int i:batteries)s+=min((long long)i,threshold);
        if(s>=n*threshold)return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s=0;
        for(int i:batteries)s+=i;
        long long lb=0,ub=s,ans=0;
        while(lb<=ub){
            long long mid=lb+(ub-lb)/2;
            if(possible(n,batteries,mid)){
                lb=mid+1;
                ans=mid;
            }
            else ub=mid-1;
        }
        return ans;
    }
};
