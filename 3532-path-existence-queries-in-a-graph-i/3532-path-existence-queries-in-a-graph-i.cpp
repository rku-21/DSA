class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n);
        for(int i=0; i<n; i++) parent[i]=i;
        for(int i=0; i<n-1; i++) {
            if(nums[i+1]-nums[i]<=maxDiff){
                parent[i+1]=parent[i];
            }
        }
        vector<bool>ans;

        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            if(parent[u]==parent[v]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
        
        
    }
};