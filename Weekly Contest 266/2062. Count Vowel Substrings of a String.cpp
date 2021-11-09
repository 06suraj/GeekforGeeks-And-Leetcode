class Solution {
public:
    bool isvowel(char a){
        if(a=='a' or a=='e' or a=='i' or a=='o' or a=='u')return 1;
        return 0;
    }
    int countVowelSubstrings(string word) {
        int n=word.size(),ans=0;
        for(int i=0;i<n;i++){
            int f[26]={0};
            for(int j=i;j<n;j++){
             f[word[j]-'a']++;
              int flag=0;
             for(int i1=0;i1<26;i1++){
                 if(isvowel('a'+i1) and f[i1])flag++;
                 else if(f[i1]){flag=0;break;}
             }
            if(flag==5)ans++;
             
          }
        }
        
    return ans;    
    }
   
};
