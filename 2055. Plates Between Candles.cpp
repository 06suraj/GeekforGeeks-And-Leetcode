class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size(),cnt=0,prev=-1;
        int candle_left[n],candle_right[n],prefix[n];
        
        //HERE FIRST WE STORE THE IMMEDIATE LEFT AND RIGHT PLATES FOR EACH INDEX USING PREPROCESSING (CAN ALSO BE DONE USING BINARY SEARCH DURING FURTHER CALCUALTION) AND THEN FOR EACH INDEX WE STORE THE NUMBER OF PLATES ECOUNTERED TILL NOW AND THEN FINALLY ACCORDING TO QUERY  FIND THE IMMEDIATES LEFT AND RIGHT PLATES CALCUALTE THE NUMBER OF PLATES BETWEEEN THEM USING PREFIX SUM ARRAY
        for(int i=0;i<n;i++){
            if(s[i]=='*')cnt++;
            else prefix[i]=cnt;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='*')
                candle_left[i]=prev;
            else {
                candle_left[i]=i;
                prev=i;
            }
        }
        prev=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*')candle_right[i]=prev;
            else {
                candle_right[i]=i;
                prev=i;
            }
        }
        vector<int>ans;
        for(vector<int>i:queries){
            int r=candle_right[i[0]],l=candle_left[i[1]];
            if((r==-1 or l==-1) or l<r)ans.push_back(0);
            else ans.push_back(prefix[l]-prefix[r]);
            
        }
        return ans;
    }
};
