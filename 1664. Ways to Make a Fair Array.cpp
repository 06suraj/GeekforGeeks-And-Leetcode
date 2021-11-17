class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int even_prefix=0,even_suffix=0,odd_prefix=0,odd_suffix=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)even_suffix+=nums[i];
            else odd_suffix+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(i%2){
                if(odd_prefix+even_suffix-even_prefix==even_prefix+odd_suffix-odd_prefix-nums[i])ans++;
                odd_prefix+=nums[i];
            }else{
                 if(even_prefix+odd_suffix-odd_prefix==odd_prefix+even_suffix-even_prefix-nums[i])ans++;
                even_prefix+=nums[i];
            }
            
        }
        return ans;
    }
};
