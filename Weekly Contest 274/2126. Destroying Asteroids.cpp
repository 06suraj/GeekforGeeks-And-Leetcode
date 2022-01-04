class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long s=mass;
        for(int i:asteroids){
            if(i>s)return false;
            s+=i;
            
        }
        return true;
    }
};
