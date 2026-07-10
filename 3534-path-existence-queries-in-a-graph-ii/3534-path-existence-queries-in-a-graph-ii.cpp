class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>>sorted_nums;
        for(int i=0; i<n; i++){
            sorted_nums.push_back({nums[i],i});
        }
        
        sort(sorted_nums.begin(),sorted_nums.end());
        vector<int>parent(n);
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            auto it=lower_bound(sorted_nums.begin(), sorted_nums.end(), pair<int,int>{nums[i],i});
            mp[i]=it-sorted_nums.begin();
            parent[i]=i;
        }
        int log=0;
        while( (1<<log) <n) log++;
        if(log==0) log=1;

        vector<vector<int>>up(n,vector<int>(log));
        int r=0;
        for(int l=0; l<n; l++){
            if( r<l ){
               r=l;
            }

            while(r+1<n && sorted_nums[r+1].first-sorted_nums[l].first<=maxDiff) r++;

            up[l][0]=r;
        }


        for(int k=1; k<log; k++){
            for(int i=0; i<n; i++){
                up[i][k]=up[up[i][k-1]][k-1];

            }
        }

     

        for(int i=0; i<n-1; i++){
            if(sorted_nums[i+1].first-sorted_nums[i].first<=maxDiff){
                parent[sorted_nums[i+1].second]=parent[sorted_nums[i].second];
              
            }
            

        }
              

        vector<int>ans;
        for(auto q:queries){
            int u=q[0];
            int v=q[1];

            if(parent[u]!=parent[v]) ans.push_back(-1);
              else if(u==v) ans.push_back(0);
            else if (abs(nums[u]-nums[v])<=maxDiff) ans.push_back(1);
          
           else {
                int src=mp[u];
                int dest=mp[v]; 
              

                if(src>dest) swap(src,dest);

                int curr=src;
                int jumps=0;
                
                for(int i=log-1; i>=0; i--){
                    if(up[curr][i]<dest){
                        curr=up[curr][i];
                        jumps+=(1<<i);
                        
                    }
                }
               
                if(up[curr][0]>=dest){
                    ans.push_back(jumps+1);
                }
                else ans.push_back(-1);
            }
            
        }

        return ans;






    }
};