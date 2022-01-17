class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int src=1,ans=0;
        while(target>1 and maxDoubles>0){
            if(target%2)ans+=2;
            else ans++;
            target/=2;
            maxDoubles--;
        }
        return ans+target-1;
    }
};
