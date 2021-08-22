class Solution {
public:
    int power(unsigned long long x, unsigned long long int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
    int minNonZeroProduct(int p) {
       unsigned long long x=pow(2,p),ans=1,z=pow(2,p-1);
        if(p==1)return 1;
        else if(p==2)return 6;
        else{
           unsigned long long y=x-2;
           int ans=1;
            return (power(y,y-z+1,1000000007)*((y+1)%1000000007))%1000000007;
            
            
        }
        
    }
};
