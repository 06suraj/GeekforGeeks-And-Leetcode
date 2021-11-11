class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end(),cmp);
        int maxright[n],ans=0;
         maxright[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],events[i][2]);
        }
        // for(int i:maxright)cout<<i<<" ";
        for(int i=0;i<n;i++){
            int endtime=events[i][1];
            int l=i+1,r=n-1,index=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(events[mid][0]>endtime){
                    index=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            if(index!=-1)ans=max(ans,maxright[index]+events[i][2]);
            ans=max(ans,maxright[i]);
            
        }
        return ans;
    }
};
