class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m=grid.size();
        int n=grid[0].size();

        if(k%(m*n)==0) return grid;

        k=k%(m*n);

        int i1=0,j1=0;
        int i2=m-1,j2=n-1;

        while(i1<i2 || (i1==i2 && j1<j2)){
            swap(grid[i1][j1],grid[i2][j2]);
            j1++;
            j2--;
            if(j1==n){
                j1=0;
                i1++;
            }
            if(j2==-1){
                j2=n-1;
                i2--;
            }
           
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }


        i1=0,j1=0;
        i2=(k-1)/n , j2=(k-1)%n;
        while(i1<i2 || (i1==i2 && j1<j2)){
            swap(grid[i1][j1],grid[i2][j2]);
            j1++;
            j2--;
            if(j1==n){
                j1=0;
                i1++;
            }
            if(j2==-1){
                j2=n-1;
                i2--;
            }
           
        }
        i1=k/n,j1=k%n;
        i2=m-1,j2=n-1;
        while(i1<i2 || (i1==i2 && j1<j2)){
            swap(grid[i1][j1],grid[i2][j2]);
            j1++;
            j2--;
            if(j1==n){
                j1=0;
                i1++;
            }
            if(j2==-1){
                j2=n-1;
                i2--;
            }
           
        }
        return grid;

        


        















        
    }
};