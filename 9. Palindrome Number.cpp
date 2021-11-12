class Solution {
public:
    bool isPalindrome(int x) {
        
        //1. using string
        
        // string num=to_string(x);
        // for(int i=0;i<num.size()/2;i++){
        //     if(num[i]!=num[num.size()-1-i])return 0;
        // }
        // return 1;
        
        
        //2 without converting to string
        long long   int temp=x,rev=0;
        if(x<0)return 0;
        while(x){
            int rem=x%10;
            rev=rev*10+rem;
            x/=10;
        }
        if(temp==rev)return 1;
        return 0;
    }
};
