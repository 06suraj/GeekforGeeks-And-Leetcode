class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        set<int>s;
         int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]!=0){
            int temp=digits[i];
            for(int j=0;j<n;j++){
                if(j!=i){
                    int x1=temp;
                    temp=temp*10+digits[j];
                    for(int k=0;k<n;k++){
                        if(k!=i and k!=j and digits[k]%2==0){
                            int x=temp;
                            temp=temp*10+digits[k];
                            s.insert(temp);
                            temp=x;
                        }
                    }
                    temp=x1;
                }
            }
            }
        }
        for(int i:s)ans.push_back(i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
