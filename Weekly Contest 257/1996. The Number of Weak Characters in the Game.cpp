class Solution {
public:
 int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        vector<long int>attack,defense;
        int n=properties.size();
        for(int i=0;i<properties.size();i++){
            attack.push_back(properties[i][0]);
            defense.push_back(properties[i][1]);
        }
        int cnt=0;
        long maxi[n],temp=-1;
       for(int i=n-1;i>=0;i--){
           if(temp<defense[i])
           temp=defense[i];
           maxi[i]=temp;
           
       }
        for(int i=0;i<n;i++){
            int upper=upper_bound(attack.begin(),attack.end(),attack[i])-attack.begin();
            if(upper!=n){
              if(maxi[upper]>defense[i])
                    cnt++;
            }
        }
        return cnt;
    }

};
