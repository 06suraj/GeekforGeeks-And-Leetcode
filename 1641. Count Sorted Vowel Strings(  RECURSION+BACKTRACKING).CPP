class Solution {
public:
    
//     RECURSION+BACKTRACKING
//    T.C=EXPONENTIAL
    
    void solve(string&temp,string vowel,int i,int n,int& cnt){
        if(temp.size()==n)
        {
            cnt++;
            return ;
        }
        if(i>=5)return ;
        temp+=vowel[i];
        solve(temp,vowel,i,n,cnt);
        temp.pop_back();
        solve(temp,vowel,i+1,n,cnt);
        
    }
    int countVowelStrings(int n) {
        string temp="",vowel="aeiou";
        int cnt=0;
        solve(temp,vowel,0,n,cnt);
        return cnt;
    }
};
