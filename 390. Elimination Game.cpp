class Solution {
public:
    
    // NICE OBSERVATION 
     // T.C.= O(logn)
    
    int lastRemaining(int n) {
        int ans=1,step=1,rem=n,dir=1;   // 1 -> right to left and 0 -> left to right
        while(rem>1){
            if(dir)ans+=step;
            else {
                if(rem%2)ans+=step;
            }
            dir= !dir;
            rem/=2;
            step=step*2;
        }
        return ans;
    }
};
