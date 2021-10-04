class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s=0,m=rolls.size();
        for(int i:rolls)s+=i;
        int req=mean*(n+m)-s;
         vector<int>ans(n);
        if(req%n){
           for(int i=0;i<n;i++)ans[i]=req/n;
            for(int i=0;i<req%n;i++)ans[i]+=1;
            
        }else{
              for(int i=0;i<n;i++)ans[i]=req/n;
        }
        for(int i:ans){
            if(i<1 or i>6)return {};
        }
        return ans;
    }
};
