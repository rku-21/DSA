class Solution {
public:
    vector<bool>vis;
    pair<int,int> dfs(int node, auto&adj){
        vis[node]=true;
        cout<<"vis--> "<<node<<endl;
         pair<int,int>tempAns={0,0};
        for(auto neig:adj[node]){
            if(!vis[neig]){
                pair<int,int> data=dfs(neig,adj);
                
                 tempAns.first+=data.first;
                 tempAns.second+=data.second;

            }
        }
        tempAns.first+=1;
        tempAns.second+=adj[node].size();
        return tempAns;

        


    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vis.resize(n,false);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans=0;

        for(int i=0; i<n; i++){
           if(!vis[i]){
            // cout<<"dfs call for "<<i<<endl;
              pair<int,int> data=dfs(i,adj);
            int nodes=data.first;
            int Edges=data.second/2;
            int completeEdges=(nodes*(nodes-1))/2;
            if(completeEdges==Edges) ans++;
           }



        }
        return ans;





        
    }
};