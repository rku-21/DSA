class Solution {
public:
    int m;
    unordered_map<long long,int>dp;
    long long getkey(int l ,int r){
        return (1LL*l<<32) |r;
    }
    int solve(int l, int r, auto&cuts){
        if(l>=r) return 0;
        long long key=getkey(l,r);
        if(dp.count(key)) return dp[key];
        auto itStart=upper_bound(cuts.begin(),cuts.end(),l);
        auto itEnd=lower_bound(cuts.begin(), cuts.end(),r);
        if(itStart==cuts.end()) return 0;

        int ans=INT_MAX;
        while(itStart!=itEnd){
            int cutsIdx=*itStart;
            int left=solve(l,cutsIdx,cuts);
            int right=solve(cutsIdx,r,cuts);

            int tempAns=left+right+(r-l);
            ans=min(ans,tempAns);
            itStart++;
        }

        
        return dp[key]=ans==INT_MAX?0:ans;
    }
    int minCost(int n, vector<int>& cuts) {
       m=n;
        sort(cuts.begin(), cuts.end());
        return solve(0,n,cuts);
        
    }
};