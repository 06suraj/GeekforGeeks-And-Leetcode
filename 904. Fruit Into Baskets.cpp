class Solution {
public:
    
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>check;
        int i=0,j=0,ans=0;
        while(j<fruits.size()){
            if(check.find(fruits[j])!=check.end()){check[fruits[j]]++;j++;}
            else{
                if(check.size()<2){
                    {check[fruits[j]]++;j++;}
                }else{
                    ans=max(ans,j-i);
                    while(1){
                        check[fruits[i]]--;
                        if(check[fruits[i]]==0){
                            check.erase(fruits[i]);
                            break;
                        }
                        i++;
                    }
                    i++;
                    check[fruits[j]]++;
                    j++;
                }
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};
