class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=0,j=1,n=arr.size(),ans=0,hill=1;
        while(j<n){
            if(arr[j]>arr[j-1]){
                if(hill)j++;
                else{
                    ans=max(ans,j-i);
                    i=j-1;
                    hill=1;
                }
            }else if(arr[j]<arr[j-1]){
                if(!hill)j++;
                else{
                   if(j-i+1>=3){
                       j++,hill=0;
                   }else j++,i=j-1;
                }
            }else{
             if(!hill)ans=max(ans,j-i);
             j++,i=j-1,hill=1;
            }
        }
        if(!hill)ans=max(ans,j-i);
        return ans;
        
    }
};
