class Solution {
public:
    
    // HERE WE JUST MAINTAIN TWO ARRAYS FOR PREFIX AND SUFFIX WHICH STORES NUMBER OF DISTINCT LETTERS UPTO i'th INDEX ,FROM START AND END SIMULTANEOUSLY AND THEN FOR EACH INDEX WE JUST CHECK IF PRFIX[I]==SUFFIX[I+1];
    
// T.C=O(N*26)
    
    int numSplits(string s) {
       int prefix[s.size()],suffix[s.size()],f[26],ans=0;
       memset(prefix,0,sizeof(prefix));
       memset(suffix,0,sizeof(suffix));
       memset(f,0,sizeof(f));
       prefix[0]=1,f[s[0]-'a']++;
       for(int i=1;i<s.size();i++){
           if(f[s[i]-'a']==0)prefix[i]=prefix[i-1]+1,f[s[i]-'a']++;
           else prefix[i]=prefix[i-1];
       }
       for(int i=0;i<26;i++)f[i]=0;
       suffix[s.size()-1]=1,f[s[s.size()-1]-'a']++;
       for(int i=s.size()-2;i>=0;i--){
           if(f[s[i]-'a']==0)suffix[i]=suffix[i+1]+1,f[s[i]-'a']++;
           else suffix[i]=suffix[i+1];
       }
       for(int i=0;i<s.size()-1;i++){
           if(prefix[i]==suffix[i+1])ans++;
       }
        return ans;
        
    }
};
