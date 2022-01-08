class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>frequency;
        int ans=0;
        for(string s:words)frequency[s]++;
        for(auto itr:frequency){
            cout<<itr.first;
               string curr=itr.first,rev=curr;
               reverse(rev.begin(),rev.end());
               if(frequency.find(rev)!=frequency.end() and  curr[0]!=curr[1]){
                   int cnt=min(frequency[rev],frequency[curr]);
                   ans+=4*cnt;
                   frequency[rev]=0;
               }
            if(curr[0]!=curr[1])
             frequency[curr]=0;
            
        }
        int temp=0,flag=0;
        for(auto itr:frequency){
               int cnt=itr.second;
               if(cnt%2){cnt--;flag=1;}
               ans+=2*cnt;
               temp=max(temp,2*cnt);
        }
        return max(ans+2*flag,temp);
    }
};
