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
    
     // observation+prefixsum
    //  T.C=O(n*5)    
    int solve1(int n){
        vector<int>vowel(5,1);
        
        for(int i=2;i<=n;i++){
            for(int j=3;j>=0;j--)vowel[j]+=vowel[j+1];
        }
        
        int sum=0;
        for(int i:vowel)sum+=i;
        return sum;
        
    }
    
    int countVowelStrings(int n) {
        string temp="",vowel="aeiou";
        int cnt=0;
        // solve(temp,vowel,0,n,cnt); // BACKTRACKING+REURSION
        return(solve1(n));       // observation+prefixsum
        // return cnt;
    }
};
