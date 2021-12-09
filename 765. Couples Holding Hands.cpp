class Solution {
public:
    unordered_map<int,int>pos;
    void swap(int pos1,int pos2,vector<int>&row){
        int temp=pos[pos1];
        pos[pos1]=pos[pos2];
        pos[pos2]=temp;
        row[pos[pos1]]=pos1;
        row[pos[pos2]]=pos2;
        
    }
    int minSwapsCouples(vector<int>& row) {
        pos.clear();
        ///simple implementation of hashmap , just a greedy , although hard to proof
        int ans=0,n=row.size(),find;
        for(int i=0;i<n;i++){
            pos[row[i]]=i;
        }
        for(int i=0;i<n;){
            if(row[i]%2)find=row[i]-1;
            else find=row[i]+1;
            if(row[i+1]!=find){
                swap(row[i+1],find,row);
                ans++;
            }
            i=i+2;
        }
        return ans;
    }
};
