class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int>ans(1001);
        for(int i=0; i<items1.size(); i++) {
            int idx=items1[i][0];
            int w=items1[i][1];
            ans[idx]=w;
        }
        for(int i=0; i<items2.size(); i++) {
            int idx=items2[i][0];
            int w=items2[i][1];
            ans[idx]+=w;
        }
        vector<vector<int>>fans;
        for(int i=0; i<1001; i++){
            if(ans[i]==0) continue;
            fans.push_back({i,ans[i]});
        }
        return fans;


        
    }
};