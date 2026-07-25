class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(26);
        for(int i=0; i<original.size(); i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int c=cost[i];
            adj[u].push_back({v,c});
        }
        vector<vector<int>>dist(26,vector<int>(26,INT_MAX));
        for(int i=0; i<26; i++){
            // start dijstra for each 
            set<pair<int,int>>st;
            st.insert({0,i});
            dist[i][i]=0;
            while(!st.empty()){
                auto top=*st.begin();
                st.erase(top);
                int distance=top.first;
                int node=top.second;
                for(auto&n:adj[node]){
                    int neig=n.first;
                    int w=n.second;
                    if(dist[i][neig]>distance+w){
                        dist[i][neig]=distance+w;
                        st.insert({distance+w,neig});
                    }


                }

            }
        }
        long long ans=0;
        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i]) continue;
            int origi=source[i]-'a';
            int fina=target[i]-'a';
            if(dist[origi][fina]==INT_MAX) return -1;
            ans+=dist[origi][fina];
        }
        return ans;
        
    }
};