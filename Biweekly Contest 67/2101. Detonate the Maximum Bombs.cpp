class Solution {
private:
    bool disSafe(int currX,int currY,int x,int y,int r){
        int disX=abs(currX-x),disY=abs(currY-y);
        if((long long)disX*disX+(long long)disY*disY<=(long long)r*r)return 1;
        return 0;
    }
    
    void component(int src,vector<int>adj[],int vis[],int& size){
        vis[src]=1;
        size++;
        for(int i:adj[src]){
            if(vis[i]==0)component(i,adj,vis,size);
        }
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size(),ans=0;
        int vis[n];
        memset(vis,0,sizeof(vis));
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and disSafe(bombs[j][0],bombs[j][1],bombs[i][0],bombs[i][1],bombs[i][2])){
                        adj[i].push_back(j);
                    
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int size=0;
                component(i,adj,vis,size);
                ans=max(ans,size);
                for(int j=0;j<n;j++)vis[j]=0;
            }
        }
        return ans;
    }
};
