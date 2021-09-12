class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        long long cnt=0;
        map<long double,long long>ma;
        for(int i=0;i<n;i++){
            long double x=rectangles[i][0]/(long double)rectangles[i][1];
            if(ma.find(x)!=ma.end())cnt+=ma[x];
             ma[x]++;
        }
        return cnt;
    }
};
