class Solution {
public:
    string reverseWords(string s) {
        
        // 1. O(N) TIME AND O(N) SPACE USING STACK
        // stack<string>st;
        // string temp="";
        // int i=0,j=s.size()-1;
        // while(s[i]==32)i++;
        // while(s[j]==32)j--;
        // while(i<=j){
        //     if(s[i]==32){
        //         st.push(temp);
        //         if(i>0 and s[i-1]!=32)
        //         st.push(" ");
        //         temp="";
        //         i++;
        //     }else{
        //         temp+=s[i];
        //         i++;
        //     }
        // }
        // if(temp!="")st.push(temp);
        // temp="";
        // while(!st.empty()){
        //     temp+=st.top();
        //     st.pop();
        // }
        // return temp;
        
        //2 . O(N) AND O(1) TIME AND SPACE , VERY INTUITIVE SOLUTION , FIRST TRIM THE INITIAL AND LAST SPACES THEN KEEP ONLY INTERMEDIATING SPACE BETWEEN EVERY WORD AND THEN REVERSE EACH WORD AND THEN REVERSE WHOLE MODIFIED STRING
        
        int i=0,j=s.size()-1,prev,start,end,ind=0;
        
        // TRIM THE INITIAL AND ENDING SPACE
        while(s[i]==32)i++;
        while(s[j]==32)j--;
        prev=i,start=i,end=j;
        
        // TRIM THE INTERMEDIATE SPACE
       for(i=start,ind=0;i<=end;i++){
           if(s[i]==' ' and s[i-1]==' ')continue;
           s[ind++]=s[i];
       }
        
        s.erase(s.begin()+ind,s.end());
        
        //REVERSE EACH WORD
        for(i=0,start=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        //REVERSE LAST WORD
        reverse(s.begin()+start,s.end());
        //REVERSE WHOLE STRING
        reverse(s.begin(),s.end());
        return s;
        
    }
};
