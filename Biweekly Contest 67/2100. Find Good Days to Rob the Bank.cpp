class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size(),prefixMini[n],suffixMini[n],currMini=-1,index=0;
        memset(prefixMini,-1,sizeof(prefixMini));
        memset(suffixMini,-1,sizeof(suffixMini));
        for(int i=0;i<n;i++){
            if(security[i]<=currMini){
                prefixMini[i]=index;
                currMini=security[i];
            }else{
                prefixMini[i]=i;
                currMini=security[i];
                index=i;
            }
        }
        currMini=-1,index=n-1;
        for(int i=n-1;i>=0;i--){
            if(security[i]<=currMini){
                suffixMini[i]=index;
                 currMini=security[i];
            }else{
                suffixMini[i]=i;
                currMini=security[i];
                index=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(prefixMini[i]!=-1 and suffixMini[i]!=-1 and i-prefixMini[i]>=time and suffixMini[i]-i>=time)
                ans.push_back(i);
        }
        return ans;
        
    }
};
