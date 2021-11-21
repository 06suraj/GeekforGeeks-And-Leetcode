class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dis=colors[0],ans=0;
        for(int i=colors.size()-1;i>=1;i--){
            if(colors[i]!=dis){
            ans=i;
            break;
            }
        }
        
        dis=colors[colors.size()-1];
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]!=dis){
                ans=max(ans,(int)colors.size()-1-i);
                break;
            }
        }
    return ans;
    }
};
