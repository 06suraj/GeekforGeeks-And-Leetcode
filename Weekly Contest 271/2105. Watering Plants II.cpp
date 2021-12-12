class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size(),currA=capacityA,currB=capacityB,cnt=0;
        for(int i=0;i<n/2;i++){
            if(currA<plants[i])
            {
                cnt++;
                currA=capacityA;
            }
            currA=currA-plants[i];
        }
        for(int j=n-1;j>=(n%2?n/2+1:n/2);j--){
            if(currB<plants[j])
            {
                cnt++;
                currB=capacityB;
            }
            currB=currB-plants[j];
        }
        if(n%2){
            if(currA>=currB){
                if(currA<plants[n/2])
                {
                cnt++;
                currA=capacityA;
                }
            }else {
                if(currB<plants[n/2])
               {
                cnt++;
                currB=capacityB;
               }
          }
        }
        return cnt;
        
    }
};
