class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>small;
        for(char i:num){
            if(small.empty())small.push(i);
            else{
                while(!small.empty() and small.top()>i and k){
                   small.pop();
                    k--; 
                }
                small.push(i);
            }
        }
        while(!small.empty() and k){
            small.pop();
             k--; 
        }
        string s="";
        while(!small.empty()){
            s+=small.top();
            small.pop();
        }
        reverse(s.begin(),s.end());
        int pos=-1;
        for(int i=0;i<s.size() and s[i]=='0';i++)pos=i;
        if(pos!=-1)s.erase(s.begin(),s.begin()+pos+1);
        if(s.empty())return "0";
        return s;
    }
};
