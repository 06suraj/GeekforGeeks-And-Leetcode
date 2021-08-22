class Solution {
public:
    int minTimeToType(string word) {
        int prev=word[0]-'a',ans=min(prev+1,26-prev+1);
        for(int i=1;i<word.size();i++)
        {
             int s=word[i]-'a',temp=max(s,prev),temp1=min(s,prev);
             ans+=min(temp-temp1,26-temp+temp1);
            ans++;
            prev=s;
        
        }
        return ans;
    }
};
