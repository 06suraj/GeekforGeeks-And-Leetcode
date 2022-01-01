class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>supply,check;
        vector<string>ans;
        for(string s:supplies)supply.insert(s);
        int flag1=0;
        //brute force solution using unordered set
        
        // while(true){
        //     flag1=0;
        //    for(int i=0;i<recipes.size();i++){
        //        if(check.find(recipes[i])==check.end()){
        //            int flag=0;
        //            for(string s:ingredients[i]){
        //                if(supply.find(s)==supply.end()){flag=1;break;}
        //            }
        //            if(!flag){ans.push_back(recipes[i]);supply.insert(recipes[i]);check.insert(recipes[i]);flag1=1;}
        //        }
        //    }
        //   if(flag1==0)break;
        // }
        
        // since here any dish can be dependent on other dish (i.e. one dish can notbe made untill and unless the dependent dish will not be prepare) so its seem to be some use of topo sort
        map<string,vector<string>>adj; //creates a graph for dished
        map<string,int>indegree;
        for(int i=0;i<recipes.size();i++){
            for(string s:ingredients[i]){
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        // kahn's algo for topo sort
        queue<string>q;
        for(string s:supplies)q.push(s);
        while(!q.empty()){
            string ingred=q.front();
            q.pop();
            for(auto recipe:adj[ingred]){
                indegree[recipe]--;
                if(indegree[recipe]==0){ans.push_back(recipe);q.push(recipe);}
            }
        }
        
        return ans;
    }
};
