class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if(original.size()!=n*m)return ans;
        else{
            int i=0,cnt=1;
            vector<int>temp;
            while(i<n*m){
                if(i==cnt*n-1){
                    temp.push_back(original[i]);
                    ans.push_back(temp);
                    temp.clear();
                    cnt++;
                }else {
                    temp.push_back(original[i]);
                }
                i++;
            }
        }
        return ans;
    }
};
