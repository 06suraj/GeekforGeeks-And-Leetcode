class Solution {
public:
   
//     we can solve using bitset where each index will be our sum and we will find all possible sums till current row  by shift(left) previous sums to current row element 
    
//  this is much faster than dp (memo) approach
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
       bitset<4901>p(1);  // intialise with sum as 0
        for(auto row:mat){
            bitset<4901>temp;
            for(auto ele:row)
                temp=temp|(p<<ele);
            swap(temp,p);
        }
        int res=INT_MAX;
        for(int i=0;i<4901;i++){
            if(p[i])res=min(res,abs(i-target));
        }
        return res;
    }
};
