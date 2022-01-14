class Solution {
public:
    //gfg
    int minswaps(vector<int>arr, int n)
{
  int totalCount = 0;
  for (int i = 0; i < n; i++)
    totalCount += arr[i];

  int currCount = 0; 
  int maxCount = 0;  // To store maximum count ones out of all windows
  int i = 0;         // start of window
  int j = 0;         // end of window

  while (j < n)
  {
    currCount += arr[j];

    // update maxCount when reach window size i.e. total count of ones in array
    if ((j - i + 1) == totalCount)
    {
      maxCount = max(maxCount, currCount);
      if (arr[i] == 1)
        currCount--; // decrease current count if first element of window is 1
      i++;           // slide window
    }
    j++;
  }

  return totalCount - maxCount; // return total no of ones in array - maximum count of ones out of all windows
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),ans=minswaps(nums,n);
        int cnt=0,temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)cnt++;
        }
        int prefix[n],suffix[n];
        memset(prefix,0,sizeof(prefix));
        memset(suffix,0,sizeof(suffix));
        if(nums[0]==1)prefix[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]==1)prefix[i]=prefix[i-1]+1;
            else prefix[i]=prefix[i-1];
        }
        if(nums[n-1]==1)suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1)suffix[i]=suffix[i+1]+1;
            else suffix[i]=suffix[i+1];
        }
        for(int i=0;i<cnt-1;i++){
            temp=max(temp,prefix[i]+suffix[n-cnt+i+1]);
        }
        ans=min(ans,cnt-temp);
        return ans;
        
        
    }
};
