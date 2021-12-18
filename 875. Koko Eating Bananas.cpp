class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int lb=1,ub=piles[piles.size()-1],ans=-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            int cnt=0;
            for(int i=0;i<piles.size();i++){
                cnt+=ceil(piles[i]/(double)mid);
            }
            if(cnt>h)lb=mid+1;
            else {
                ub=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
