class Solution {
public:
    int countValidWords(string sentence) {
        string word="";
        int ans=0;
        for(char i:sentence){
            if(i==' ')
            {
                int cnt=0,flag=0,flag1=0;;
                for(int j=0;j<word.size();j++){
                   flag1=1;
                    if(word[j]>='0' and word[j]<='9')flag=1;
                    else if(word[j]=='-'){
                        if(j==0 or j==word.size()-1 or cnt)flag=1;
                        else if(word[j-1]<'a' or word[j-1]>'z')flag=1;
                        else if(word[j+1]<'a' or word[j+1]>'z')flag=1;
                        else cnt=1;
                    }else if(word[j]=='!' and j!=word.size()-1)flag=1;
                    else if((word[j]=='.' or word[j]==',') and (j!=word.size()-1))flag=1;
                }
                cout<<word<<endl;
                if(flag==0 and flag1==1){ans++;}
                // else cout<<word<<endl;
                word="";
            }
            else word+=i;
        }
        int cnt=0,flag=0,flag1=0;
                for(int j=0;j<word.size();j++){
                     flag1=1;
                    if(word[j]>='0' and word[j]<='9')flag=1;
                    else if(word[j]=='-'){
                        if(j==0 or j==word.size()-1 or cnt)flag=1;
                        else if(word[j-1]<'a' or word[j-1]>'z')flag=1;
                        else if(word[j+1]<'a' or word[j+1]>'z')flag=1;
                        else cnt=1;
                    }else if(word[j]=='!' and j!=word.size()-1)flag=1;
                    else if((word[j]=='.' or word[j]==',') and (j!=word.size()-1)){flag=1;}
                }
        if(flag==0 and flag1==1)ans++;
        cout<<word<<endl;
        
        return ans;
    }
};
