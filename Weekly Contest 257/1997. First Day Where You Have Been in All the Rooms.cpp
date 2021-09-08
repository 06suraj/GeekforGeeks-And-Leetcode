#define mod 1000000007
class Solution {
public:
    
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n=nextVisit.size();
       long long int day[n];
         day[0]=2;  // day [i] represents total number of days to reach i+1 th room from ith room
        for(int i=1;i<n-1;i++){
            if(nextVisit[i])
                day[i] = (2 + 2 * day[i - 1] - day[nextVisit[i]-1]+mod) % mod;
            else day[i]= (2 + 2 * day[i - 1]+mod)% mod;
        }
        return day[n-2];
    }
};
