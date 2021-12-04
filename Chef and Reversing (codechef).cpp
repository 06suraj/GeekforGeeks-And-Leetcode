#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(int i=0;i<m;i++){
	    int u,v;cin>>u>>v;
	    adj[u].push_back({v,0});
	    adj[v].push_back({u,1});
	}
	vector<int>dis(n+1,INT_MAX);
	deque<int>q;
	dis[1]=0;
	q.push_back(1);
	while(!q.empty()){
	    int u=q.front();
	    q.pop_front();
	    for(auto i:adj[u]){
	        int v=i.first,w=i.second;
	        if(dis[v]>dis[u]+w){
	            dis[v]=dis[u]+w;
	            if(w==1)q.push_back(v);
	            else q.push_front(v);
	        }
	    }
	}
	cout<<(dis[n]==INT_MAX?-1:dis[n])<<endl;
	return 0;
}
