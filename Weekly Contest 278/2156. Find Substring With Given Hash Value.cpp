class Solution {
public:
    /* naive approach would be to check all substrings of length of k whether it will give me answer or not
     but that would cost me o(n*k)  which results into TLE
         
     then we think of Sliding window 
     but if we go from left to right and try to divide the result then it would not be possible as in modular            division direct division is not possible , to do that we need modular inverse and for that p as well as mod        value needs to be prime , which is not given here, 
    so to find answer we will move from right to left and using multiplication and that would give me answer in         o(n) */

    string subStrHash(string s, long long int power, long long int modulo,long long  int k,long long int hashValue) {
        long long hash=0,pr=1;
        int n=s.size(),ind;
        for(int i=n-1;i>=0;i--){
            hash=((hash*power)%modulo+(s[i]-'a'+1)*1)%modulo;
            // should i remove or not from current window
        
            if(i+k>=n){   //include
                pr=(pr*power)%modulo;
            }else{     //exclude
                hash=((hash-(s[i+k]-'a'+1)*pr)%modulo+modulo)%modulo; 
            }
            
            
            if(hash==hashValue){
                ind=i;
            }
        }
        return s.substr(ind,k);
    }
};
