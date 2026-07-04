class Solution {
public:
    int ans=INT_MAX;
    void dfs(int node, auto&adj,auto&vis){
        vis[node]=true;

        for(auto n:adj[node]){
            int neig=n.first;
            int w=n.second;
            ans=min(ans,w);
            if(vis[neig]) continue;
            dfs(neig, adj,vis);
            

        }

    }
    int minScore(int n, vector<vector<int>>& roads) {

         vector<vector<pair<int,int>>>adj(n+1);
         for(auto road:roads){
             adj[road[0]].push_back({road[1],road[2]});
             adj[road[1]].push_back({road[0],road[2]});
         }

         vector<bool>vis(n,false);

         dfs(1,adj,vis);
         return ans;




        
    }
};