class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size(),mal=0,mar=0,mil=0,mir=0,maxi=*max_element(nums.begin(),nums.end()),mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){mal++;break;}
            else mal++;
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxi){mar++;break;}
            else mar++;
        }
        mal=min(mal,mar);
        for(int i=0;i<n;i++){
            if(nums[i]==mini){mil++;break;}
            else mil++;
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]==mini){mir++;break;}
            else mir++;
        }
        mil=min(mil,mir);
        int tot=0,flag=0,tot1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi and flag==1){
                flag++;
                tot++;
                break;
            }else if(nums[i]==mini and flag==1){
                flag++;
                tot++;
                break;
            }else if(nums[i]==maxi or nums[i]==mini){
                flag++;
                tot++;
            }else tot++;
        }
        flag=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxi and flag==1){
                flag++;
                tot1++;
                break;
            }else if(nums[i]==mini and flag==1){
                flag++;
                tot1++;
                break;
            }else if(nums[i]==maxi or nums[i]==mini){
                flag++;
                tot1++;
            }else tot1++;
        }
        tot=min(tot,tot1);
        return (min(mal+mil,tot));
        
    }
};
