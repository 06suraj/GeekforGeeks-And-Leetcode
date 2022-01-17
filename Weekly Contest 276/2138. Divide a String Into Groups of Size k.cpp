class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        for(int i=0;i<s.size();i=i+k){
            string temp="";
            for(int j=i;j<s.size() and j<i+k;j++)temp+=s[j];
            int diff=k-temp.size();
            while(diff>0){temp+=fill;diff--;}
            ans.push_back(temp);
            
        }
        return ans;
    }
};
