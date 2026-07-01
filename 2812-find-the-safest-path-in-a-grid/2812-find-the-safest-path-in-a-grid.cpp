class Solution {
public:
    int n,m;
    vector<vector<int>>storeM;
    int dir[5]={1,0,-1,0,1};

    bool dfs(int row, int col , auto&grid,auto&vis){
        vis[row][col]=true;

       

        if(row==n-1 && col==n-1) return true;


        for(int d=0; d<4; d++){
                int newRow=row+dir[d];
                int newCol=col+dir[d+1];
              if(newRow>=0 && newRow<n && newCol>=0 && newCol<n){
                  if(!vis[newRow][newCol] && grid[newRow][newCol]==1){
                bool ans=dfs(newRow,newCol,grid,vis);
                if(ans) return true;
    
              }
              }
        }

        return false;





    }


    bool possible(int sfactor,vector<vector<int>> grid,auto vis){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(storeM[i][j]<sfactor){
                    grid[i][j]=0; // block the path 
                }
                else grid[i][j]=1;
            }
        }

        if(grid[0][0]==0 || grid[n-1][n-1]==0) return false;

        return dfs(0,0,grid,vis);


    }






    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n=grid.size();

        n=grid[0].size();
        storeM.resize(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));


        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    storeM[i][j]=0;
                    vis[i][j]=true;
                    q.push({i,j});

                }
                
                
            }
        }

        

        while(!q.empty()){
            // cout<<"runing bfs"<<endl;
            auto  front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;

            

            for(int d=0; d<4; d++){
                int newRow=x+dir[d];
                int newCol=y+dir[d+1];
                // cout<<newRow<<" "<<newCol<<endl;
                if(newRow<0 || newCol<0 || newRow>=n || newCol>=n || vis[newRow][newCol]) continue;
                int mdist=abs(x-newRow)+abs(y-newCol)+storeM[x][y];
                // cout<<mdist<<endl;
                if(storeM[newRow][newCol]>mdist){
                    storeM[newRow][newCol]=mdist;
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=true;
                }
            }
        }

        vis=vector<vector<bool>>(n,vector<bool>(n,false));

        vector<int>factors;
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                factors.push_back(storeM[i][j]);
                // cout<<storeM[i][j]<<" ";
            }
            // cout<<endl;
        }

        sort(factors.begin(), factors.end());



        int low=0;
        int high=factors.size()-1;

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(factors[mid],grid,vis)){
                ans=factors[mid];
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;













        
        
    }
};