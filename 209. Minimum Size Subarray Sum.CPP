class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int i=0,j=0,ans=INT_MAX,sum=0;
        
        // 1.TWO - POINTER O(N)
        
        while(j<arr.size()){
                if(sum>=target){
                    ans=min(ans,j-i);
                    sum-=arr[i];
                    i++;
                }else
                    sum+=arr[j++];
                    
            }
        
        while(i<j){
               if(sum>=target){
                    ans=min(ans,j-i);
                    sum-=arr[i];
               }
                    i++;
                 
        }
        if(sum>=target)ans=min(ans,j-i);
        // if(ans==INT_MAX)return 0;
        // return ans;
        
        
        // 2 BINARY SEARCH O(NLOGN)
        
        ans=INT_MAX;
        for(int i=1;i<arr.size();i++)arr[i]=arr[i-1]+arr[i];
        for(int i=0;i<arr.size();i++){
            int index=lower_bound(arr.begin(),arr.end(),arr[i]+target)-arr.begin();
            if(index!=arr.size())
                ans=min(ans,index-i);
            if(arr[i]>=target)ans=min(ans,i+1);
        }
        
        if(ans==INT_MAX)return 0;
        return ans;
       
    }
};
