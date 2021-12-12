class Solution {
private:
     void preCompute(int arr[], int n, int pre[])
  {
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
  }
    
  int rangeSum(int i, int j, int pre[],int n)
   {
    if(i>j or (i<0 and j<0))return 0;
        if(j>=n)j=n-1;
    if (i <= 0)
        return pre[j];
 
     return pre[j] - pre[i - 1];
   }
    
public:
  int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxiLen=fruits[fruits.size()-1][0];
        maxiLen++;
        maxiLen=max(maxiLen,startPos+1);
        int arr[maxiLen];
        memset(arr,0,sizeof(arr));
        for(vector<int>v:fruits){
            arr[v[0]]=v[1];
        }
        int pre[maxiLen];
        preCompute(arr,maxiLen,pre);
        int ans=0,sum=0,cnt=0;
        for(int i=startPos;i<=startPos+k and i<maxiLen;i++){
            sum+=arr[i];
            ans=max(ans,rangeSum(i-k+cnt,startPos-1,pre,maxiLen)+sum);
            if(ans==11)cout<<i-k<<" "<<startPos-1<<endl;
            cnt++;
            
        }
        sum=0,cnt=0;
        for(int i=startPos;i>=startPos-k and i>=0;i--){
            sum+=arr[i];
            ans=max(ans,rangeSum(startPos+1,i+k-cnt,pre,maxiLen)+sum);
            cnt++;
        }
        return ans;
        
    }
};
