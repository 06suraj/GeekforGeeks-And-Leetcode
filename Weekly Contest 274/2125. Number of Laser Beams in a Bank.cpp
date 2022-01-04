class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=-1,ans=0;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')cnt++;
            }
            if(prev==-1)prev=cnt;
            else if(cnt){ans+=prev*cnt;prev=cnt;}
        }
        return ans;
    }
};
