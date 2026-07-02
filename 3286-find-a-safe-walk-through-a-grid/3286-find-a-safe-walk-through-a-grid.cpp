class Solution {
public:
    int m,n;
    bool dfs(int row, int col , auto&vis, auto&grid, int health){
        if(health<=0) return false;
        vis[row][col][health]=true;
        if(row==m-1 && col==n-1) return true;

        

        int dir[5]={1,0,-1,0,1};
        for(int d=0; d<4; d++){
            int newRow=row+dir[d];
            int newCol=col+dir[d+1];

            if(newRow<0 || newCol<0 || newRow>=m || newCol>=n) continue;
            int newHealth=health;
            if(grid[newRow][newCol]==1) newHealth-=1;

            if(vis[newRow][newCol][newHealth]) continue;

            bool ans=dfs(newRow,newCol, vis, grid, newHealth);
            if(ans) return ans;
        }

        return false;




    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(health+1,false)));
        if(grid[0][0]==1) health-=1;

        return dfs(0,0,vis, grid,health);
        
    }
};