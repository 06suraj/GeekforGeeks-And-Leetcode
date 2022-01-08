class Solution {
public:
    int minSteps(string s, string t) {
     int n=s.size(),f[26]={0},ans=0;
     for(char i:s)f[i-'a']++;
     for(char i:t)f[i-'a']--;
     for(int i:f){
         if(i>0)ans+=i;
     }
    return ans;
     
    }
};
