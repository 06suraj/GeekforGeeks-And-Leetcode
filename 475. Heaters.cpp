class Solution {
public:
    vector<int>search(int target,vector<int>&heaters,int m){
        int greater=-1,smaller=-1;
        int l=0,r=m-1;
        while(l<=r){
            int mid=l + (r - l) / 2;
            if(heaters[mid]==target)return {mid,mid};
            else if(heaters[mid]>target){
                greater=mid;
                r=mid-1;
            }else{
               smaller=mid;
                l=mid+1;
            }
        }
        return {greater,smaller};
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=INT_MIN,n=houses.size(),m=heaters.size();
        
        // 1.BINARY SEARCH O(N^2) TO O(NLOGN)
        
        for(int i=0;i<houses.size();i++){
            
            vector<int>dist=search(houses[i],heaters,m);
            
            if(dist[0]==-1){
                ans=max(ans,abs(heaters[dist[1]]-houses[i]));
            }else if(dist[1]==-1)
            {
                 ans=max(ans,abs(heaters[dist[0]]-houses[i]));
            }
            else 
            {
                int temp=min(abs(heaters[dist[0]]-houses[i]),(abs(heaters[dist[1]]-houses[i])));
                 ans=max(ans,temp);
            }
           
        }
        
        // 2.TWO POINTER O(NLOGN)->O(N)
        
        ans=INT_MIN;
        if(m==1)return max(abs(houses[n-1]-heaters[0]),abs(houses[0]-heaters[0]));
        int i=0,next=i+1,j=0;
        while(next<m and j<n){
            if(houses[j]>=heaters[i] and houses[j]<=heaters[next])
            {
                ans=max(ans,min(houses[j]-heaters[i],heaters[next]-houses[j]));
                j++;
            }else if(houses[j]<heaters[i])
                ans=max(ans,abs(houses[j++]-heaters[i]));
            else i++,next++;
        }
        
        if(j!=n)
            ans=max(ans,abs(heaters[i]-houses[n-1]));
        return ans;
        
        
    }
};
