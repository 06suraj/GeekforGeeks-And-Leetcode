class Solution {
public:
    int minimumBuckets(string street) {
        int n=street.size(),i=0,flag=0,cnt=0;
        vector<int>vis(n,0);
        for(i=0;i<n;i++){
            if(street[i]=='.' and flag)break;
            else if(street[i]=='H')flag=1;
        }
        flag=0;
        while(i<n){
            if(street[i]=='.'){
                if((i>0 and street[i-1]=='H' and vis[i-1]==0) and (i<n-1 and street[i+1]=='H' and vis[i+1]==0)){
                    vis[i-1]=1;
                    vis[i+1]=1;
                    cnt++;
                }
            }
            i++;
        }
        for(int j=0;j<n;j++){
            if(street[j]=='.' and j+1<n and street[j+1]=='H' and vis[j+1]==0){vis[j+1]=1;cnt++;}
            if(street[j]=='.' and j-1>=0 and street[j-1]=='H' and vis[j-1]==0){vis[j-1]=1;cnt++;}
        }
        for(int i=0;i<n;i++){
            if(street[i]=='H' and vis[i]==0)return -1;
        }
        return cnt;
    }
};
