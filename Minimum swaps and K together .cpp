// SIMPLE TWO POINTER APPROACH

// O(n) TIME AND O(1) SPACE

int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt=0,ans=0,temp=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        if(arr[i]<=k)temp++;
    }
    ans=max(ans,temp);
    int i=0,j=cnt;
    if(cnt==0)return 0;
    while(j<n){
        ans=max(ans,temp);
        if(arr[i++]<=k)temp--;
        if(arr[j++]<=k)temp++;
    }
    ans=max(ans,temp);
    return cnt-ans;
    
}
