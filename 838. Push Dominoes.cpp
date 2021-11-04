class Solution {
public:
    string pushDominoes(string dominoes) {
        int i=0,j=0,n=dominoes.size();
        while(j<n){
            if(dominoes[j]!='.')
            {   if(i==0 and dominoes[j]=='L' and dominoes[i]=='.'){
                while(i<j)dominoes[i++]=dominoes[j];
                }else {
                  if((j-i-1)%2)
                  {
                      int mid=i+(j-i)/2,temp=i;
                      if(dominoes[i]==dominoes[j]){
                         while(i<j)dominoes[i++]=dominoes[j];
                      }
                      else {
                          if(dominoes[i]=='R' and dominoes[j]=='L'){
                              while(i<mid)dominoes[i++]=dominoes[temp];
                               i++;
                               while(i<j)dominoes[i++]=dominoes[j];
                          }
                          else i=j;
                      }
                  }else{
                      
                       if(dominoes[i]==dominoes[j]){
                         while(i<j)dominoes[i++]=dominoes[j];
                      }
                      else {
                          if(dominoes[i]=='R' and dominoes[j]=='L'){
                              int mid=i+(j-i)/2,temp=i;
                              while(i<=mid)dominoes[i++]=dominoes[temp];
                             while(i<j)dominoes[i++]=dominoes[j];
                          }else i=j;
                      }
                  }
            }
             
             j++;   
            }
            else j++;
        }
        int temp=i;
         while(i<n and dominoes[temp]=='R')dominoes[i++]=dominoes[temp];
        return dominoes;
    }
};
