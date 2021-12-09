class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);  // always consider nums1 to be minimum size
        int n1=nums1.size(),n2=nums2.size();
        int lb=0,ub=nums1.size();
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            int cut1=mid;
            int cut2=(n1+n2+1)/2-cut1; // alternative for (n1+n2)%2?(n1+n2)/2+1-cut1:(n1+n2)/2-cut1
    
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            int right1=cut1==n1?INT_MAX:nums1[cut1];
            int right2=cut2==n2?INT_MAX:nums2[cut2];
            if(left1<=right2 and left2<=right1){
                double median=(n1+n2)%2?max(left1,left2):(max(left1,left2)+min(right1,right2))/2.0;
                return median;
            }else if(left1>right2){
                ub=mid-1;
            }else lb=mid+1;
        }
        return -1;
    }
};
