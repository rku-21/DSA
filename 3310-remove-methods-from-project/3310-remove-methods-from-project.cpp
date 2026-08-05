class Solution {
public:
    vector<bool>isSus;
   
    void dfs(int node, auto&adj){
       isSus[node]=true;
     

        for(auto neig:adj[node]){
            if(isSus[neig]) continue;
            dfs(neig,adj);
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto e:invocations){
            adj[e[0]].push_back(e[1]);
           
        }
        isSus.resize(n,false);
        dfs(k,adj);
        vector<int>ans;
        bool noPossible=false;
        for(auto a:invocations){
            if(isSus[a[0]]==false && isSus[a[1]]) {
                noPossible=true;
                break;
            }
        }
       
        if(noPossible){
            for(int i=0; i<n; i++) ans.push_back(i);
            return ans;
        }
        for(int i=0; i<n; i++){
            if(isSus[i]==false) ans.push_back(i);
        }
        return ans;
       




    
        
    }
};