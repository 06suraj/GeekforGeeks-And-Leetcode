class Solution {
public:
    bool checkString(string s) {
        int f=0;
        for(char i:s){
            if(i=='b')f=1;
            if(i=='a' and f)return false;
        }
        return true;
    }
};
