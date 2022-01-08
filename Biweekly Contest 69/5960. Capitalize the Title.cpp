class Solution {
public:
    string capitalizeTitle(string title) {
        int cnt=0,prev=-1;
        for(int i=0;i<title.size();i++){
            if(title[i]>=65 and title[i]<=90)title[i]=title[i]+32;
        }
        for(int i=0;i<title.size();i++){
          if(title[i]==' '){
              if(cnt>2)title[prev]=title[prev]-32;
              cnt=0;
              prev=-1;
          }else{
              if(prev==-1)prev=i;
              cnt++;
          }   
        }
        if(cnt>2)title[prev]=title[prev]-32;
        return title;
    }
};
