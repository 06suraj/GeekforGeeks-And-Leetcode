class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int curr=capacity,n=plants.size(),ans=0;
        for(int i=0;i<n;i++){
            if(plants[i]>curr){
                ans+=2*i+1;
                curr=capacity-plants[i];
            }else{
                ans++;
                curr-=plants[i];
            }
        }
        return ans;
    }
};
