class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt=0;
        for(string s:operations){
            if(s[0]=='+' or s[2]=='+')cnt++;
            else cnt--;
        }
        return cnt;
    }
};
