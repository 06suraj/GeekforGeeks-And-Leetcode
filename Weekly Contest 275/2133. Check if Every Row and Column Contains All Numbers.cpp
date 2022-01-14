class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size(),flag=0;
        for(int i=0;i<n;i++){
            set<int>s;
            for(int j=0;j<n;j++){
                s.insert(matrix[i][j]);
            }
            if(s.size()<n)flag=1;
            
        }
        for(int j=0;j<n;j++){
            set<int>s;
            for(int i=0;i<n;i++){
                s.insert(matrix[i][j]);
            }
            if(s.size()<n)flag=1;
        }
        
        return !flag;
    }
};
