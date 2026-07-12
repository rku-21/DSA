class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        int r=1,n=arr.size();
        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;
        for(int i=0; i<n; i++){
            if(rank.count(temp[i])) continue;
            rank[temp[i]]=r++;
        }
        for(int i=0; i<n; i++){
            arr[i]=rank[arr[i]];

        }
     return arr;
        
        
    }
};