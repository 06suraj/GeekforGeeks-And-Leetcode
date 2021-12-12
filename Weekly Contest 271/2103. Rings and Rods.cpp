class Solution {
public:
    int countPoints(string rings) {
        map<int,set<int>>ma;
        int n=rings.size();
        for(int i=0;i<n;i=i+2){
            ma[rings[i+1]].insert(rings[i]);
        }
        int cnt=0;
        for(auto itr=ma.begin();itr!=ma.end();itr++){
            set<int>temp=(itr->second);
            if(temp.size()==3)cnt++;
        }
        return cnt;
    }
};
