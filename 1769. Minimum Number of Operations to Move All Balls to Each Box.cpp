class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;i<boxes.size();i++){
            int s=0,s1=0,s2=0;
            for(int j=i+1;j<boxes.size();j++){
                if(boxes[j]=='1')s+=j-i;
            }
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1')s+=i-j;
            }
            ans.push_back(s);
        }
        return ans;
    }
};
