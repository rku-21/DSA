class Solution {
public:
    typedef long long ll;

    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        vector<vector<vector<ll>>> dist(
            m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));

        ll start = 1LL;

        dist[0][0][1] = start;

        set<tuple<ll,int,int,int>> st;
        st.insert({start,0,0,1});

        while(!st.empty()){

            auto it = st.begin();
            auto [cost,row,col,parity] = *it;
            st.erase(it);

            if(cost!=dist[row][col][parity]) continue;

            if(row==m-1 && col==n-1) return cost;

            
            // wait 
            if(dist[row][col][parity^1]>cost+penalty[row][col]){
                dist[row][col][parity^1]=cost+penalty[row][col];
                st.insert({cost+penalty[row][col],row,col,parity^1});
            }

            if(parity==1){

                if(col+1<n){
                    ll nc = cost + 1LL*(row+1)*(col+2);
                    if(dist[row][col+1][0] > nc){
                        dist[row][col+1][0]=nc;
                        st.insert({nc,row,col+1,0});
                    }
                }

            
                if(row+1<m){
                    ll nc = cost + 1LL*(row+2)*(col+1);
                    if(dist[row+1][col][0] > nc){
                        dist[row+1][col][0]=nc;
                        st.insert({nc,row+1,col,0});
                    }
                }

                
                if(col-1>=0){
                    ll nc = cost + 1LL*(row+1)*(col) + penalty[row][col];
                    if(dist[row][col-1][0] > nc){
                        dist[row][col-1][0]=nc;
                        st.insert({nc,row,col-1,0});
                    }
                }

        
                if(row-1>=0){
                    ll nc = cost + 1LL*(row)*(col+1) + penalty[row][col];
                    if(dist[row-1][col][0] > nc){
                        dist[row-1][col][0]=nc;
                        st.insert({nc,row-1,col,0});
                    }
                }

            }
            else{

            
                if(col-1>=0){
                    ll nc = cost + 1LL*(row+1)*(col);
                    if(dist[row][col-1][1] > nc){
                        dist[row][col-1][1]=nc;
                        st.insert({nc,row,col-1,1});
                    }
                }

    
                if(row-1>=0){
                    ll nc = cost + 1LL*(row)*(col+1);
                    if(dist[row-1][col][1] > nc){
                        dist[row-1][col][1]=nc;
                        st.insert({nc,row-1,col,1});
                    }
                }

                
                if(col+1<n){
                    ll nc = cost + 1LL*(row+1)*(col+2) + penalty[row][col];
                    if(dist[row][col+1][1] > nc){
                        dist[row][col+1][1]=nc;
                        st.insert({nc,row,col+1,1});
                    }
                }

             
                if(row+1<m){
                    ll nc = cost + 1LL*(row+2)*(col+1) + penalty[row][col];
                    if(dist[row+1][col][1] > nc){
                        dist[row+1][col][1]=nc;
                        st.insert({nc,row+1,col,1});
                    }
                }

            }
        }

        return -1;
    }
}; 







        
    
