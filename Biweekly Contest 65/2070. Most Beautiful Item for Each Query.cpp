class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end(),cmp);
        int prefix[100001]={0};
        prefix[0]=items[0][1];
        for(int i=1;i<items.size();i++){
            prefix[i]=max(prefix[i-1],items[i][1]);
        }
    
        vector<int>ans;
        for(int i:queries){
            int lb=0,ub=items.size()-1,index=-1;
            while(lb<=ub){
                int mid=lb+(ub-lb)/2;
                if(items[mid][0]<=i){
                    index=mid;
                    lb=mid+1;
                }else ub=mid-1;
            }
            if(index==-1)ans.push_back(0);
            else ans.push_back(prefix[index]);
        }
        return ans;
        
    }
};
