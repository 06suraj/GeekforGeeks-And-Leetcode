class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0,n=s.size(),ans=0,org=k;
        while(j<n)
        {
            if(s[j]=='F'){
                if(k){
                    k--,j++;
                }else {
                    ans=max(ans,j-i);
                    if(s[i]=='F')k++;
                    i++;}
            }else j++;
        }
        ans=max(ans,j-i);
        i=0,j=0;
        k=org;
        while(j<n){
             if(s[j]=='T'){
                if(k){
                    k--,j++;
                }else 
                {
                    ans=max(ans,j-i);
                    if(s[i]=='T')k++;
                    i++;
                }
            }else j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};
