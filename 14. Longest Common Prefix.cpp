class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
       for(int i=0;i<strs[0].size();i++){
           char x=strs[0][i];
           int flag=0;
           for(int j=1;j<strs.size();j++){
               if(strs[j][i]!=x){
                   flag=1;break;
               }
           }
           if(flag==0)ans+=x;
           else break;
       }
         return ans;
    }
   
};
