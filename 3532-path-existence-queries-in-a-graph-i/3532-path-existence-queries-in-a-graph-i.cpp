class DSU { 
    public :
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
        size.resize(n+1,0);
    }

    void  do_union(int u, int v){
        u=find_parent(u);
        v=find_parent(v);
        if(u==v) return ;

        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else {
            parent[u]=v;
            size[v]+=size[u];;
        }
    }

    int find_parent(int u){
        if(u==parent[u]) return u;
        return parent[u]=find_parent(parent[u]);
    }

};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        DSU dsu(n);

        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i]<=maxDiff){
                dsu.do_union(i+1,i);
            }
        }

        vector<bool>ans;

        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            if(dsu.parent[u]==dsu.parent[v]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;




        
    }
};