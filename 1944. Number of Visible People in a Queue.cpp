class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(s.empty()){s.push(i);ans[i]=0;}
            else{
                int cnt=0;
                while(!s.empty() and heights[s.top()]<heights[i]){s.pop();cnt++;}
                if(!s.empty())cnt++;
                s.push(i);
                ans[i]=cnt;
            }
        }
        return ans;
    }
};
