class Solution {
public:
    void reverse(string& str , int l, int h)
    {
          while(l<h){
              swap(str[l],str[h]);
              l++,h--;
          }
    }
    
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                reverse(word,0,i);
                break;
            }
        }
        return word;
    }
};
