int countRev (string s)
{
    // your code here
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(st.empty())st.push(s[i]);
        else{
            if(s[i]=='}' and st.top()=='{')st.pop();
            else st.push(s[i]);
        }
    }
    int o=0,c=0;
    while(!(st.empty()))
    {
        if(st.top()=='}')c++;
        else o++;
        st.pop();
    }
    if((c+o)%2)return -1;
    else return(c/2+o/2+c%2+o%2);
} 
