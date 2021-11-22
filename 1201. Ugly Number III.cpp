class Solution {
public:
    // for every integer we need to find the number of ugly numbers  and that can be found using veinn diagram which considers A= numbers which are divisible by a, B=numbers which are divisible by b, C=numbers   which are divisble by c , similarly using set theory we will find the total numbers which are smaller than n using binary search 
    int nthUglyNumber(int n, int a, int b, int c) {
        int lb=1,ub=2000000000,ans=-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(getcount(a,b,c,mid)>=n){
                ans=mid;
                ub=mid-1;
            }else lb=mid+1;
        }
        return ans;
    }
    
   long long int getcount(long long int a,long long int b,long long int c,long long int n){
       long long int A=a,B=b,C=c,AB=(long long)(a*b)/(__gcd(a,b)),BC=(long long)(c*b)/(__gcd(c,b)),AC=(long long)(a*c)/(__gcd(a,c)),ABC=(long long)(a*BC)/(__gcd(a,BC));
        
        return n/A+n/B+n/C-n/AB-n/BC-n/AC+n/ABC;
    }
};
