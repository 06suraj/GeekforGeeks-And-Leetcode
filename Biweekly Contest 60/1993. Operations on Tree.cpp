class LockingTree {
public:
    vector<vector<int>>adj;
    vector<int>parent;
    vector<int>loc1;
    int n;
    LockingTree(vector<int>& par) {
        n=par.size();
        parent=par;
        for(int i=0;i<n;i++)loc1.push_back(0);
        adj.resize(n);
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if(loc1[num]==0){
            loc1[num]=user;
            return 1;
        }
        return 0;
    }
    
    bool unlock(int num, int user) {
        if(loc1[num]==user)
        {
            loc1[num]=0;
            return 1;
        }return 0;
    }
    
    bool upgrade(int num, int user) {
        if(loc1[num])return 0;
        
        vector<int>vis(n,0);
        vector<int>descendant;
        queue<int>q;
        q.push(num);
        vis[num]=1;
        bool flag=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto i:adj[top]){
                if(vis[i]==0){
                    q.push(i);
                    if(loc1[i]){
                    descendant.push_back(i);
                    flag=1;
                    }
                   vis[i]=1;
                }
            }
        }
        if(flag==0)return 0;
        int num1=num;
     
        while(num!=-1){
            if(loc1[num])return 0;
            num=parent[num];
        }
        for(int i:descendant)
            loc1[i]=0;
        loc1[num1]=user;
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
