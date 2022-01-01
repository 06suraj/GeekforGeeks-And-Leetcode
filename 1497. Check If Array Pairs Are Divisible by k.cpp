class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>ma;
        for(int i:arr){
            int rem=i%k;
            
            if(!rem){
                if(ma.find(rem)==ma.end())ma[rem]++;
                else ma.erase(rem);
            }
            else{
                if(rem<0){
                    if(ma.find(-1*rem)!=ma.end() and ma[-1*rem])ma[-1*rem]--;
                    else if(ma.find(-1*k-rem)!=ma.end() and ma[-1*k-rem])ma[-1*k-rem]--;
                    else ma[rem]++;
                }else{
                     if(ma.find(-1*rem)!=ma.end() and ma[-1*rem])ma[-1*rem]--;
                    else if(ma.find(k-rem)!=ma.end() and ma[k-rem])ma[k-rem]--;
                    else ma[rem]++;
                }
                
            }
        }
        for(auto i:ma){
            if(i.second)return 0;
        }
        return 1;
    }
};
