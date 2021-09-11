class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,ans=INT_MIN;
        while(l<r){
            ans=max(ans,min(height[r],height[l])*(r-l));
            if(height[l]<height[r])
                l++;
            else r--;
        }
        return ans;
    }
};
