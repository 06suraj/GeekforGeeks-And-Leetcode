class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int,int>ma;
        ma[0]=-1;
        int n=arr.size(),s=0;
        int min_left[n],min_right[n],left=INT_MAX,right=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(ma.find(s-target)!=ma.end()){
                min_left[i]=min(left,i-ma[s-target]);
                left=min(left,i-ma[s-target]);
            }
            min_left[i]=left;
            ma[s]=i;
        }
        ma.clear();
        ma[0]=n;
        s=0;
        for(int i=n-1;i>=0;i--){
            s+=arr[i];
            if(ma.find(s-target)!=ma.end()){
                min_right[i]=min(right,ma[s-target]-i);
                right=min(right,ma[s-target]-i);
            }
            min_right[i]=right;
            ma[s]=i;
        }
        for(int i=1;i<n;i++){
            if(min_left[i-1]!=INT_MAX and min_right[i]!=INT_MAX)ans=min(ans,min_left[i-1]+min_right[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
