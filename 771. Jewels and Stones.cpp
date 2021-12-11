class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int f[125]={0},ans=0;
        for(char i:jewels)f[i]++;
        for(char i:stones){
            if(f[i])ans++;
        }
        return ans;
    }
};
