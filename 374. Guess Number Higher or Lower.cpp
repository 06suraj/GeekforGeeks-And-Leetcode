/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    //BINARY SEARCH O(LOGN);
    int guessNumber(int n) {
        int lb=1,ub=n;
        while(lb<=ub){
            int mid=(lb+ub)/2;
            if(guess(mid)==0)return mid;
            else if(guess(mid)==-1)ub=mid-1;
            else lb=mid+1;
        }
      return 0;  
    }
};
