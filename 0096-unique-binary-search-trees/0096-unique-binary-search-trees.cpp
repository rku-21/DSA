class Solution {
public:
    int dp[20][20];
    int build(int s, int e) {
        if (s > e) return 1; 
        if(dp[s][e]!=-1) return dp[s][e];

        int total = 0;
        for (int i = s; i <= e; i++) {
            int left = build(s, i - 1);
            int right = build(i + 1, e);
            total += left * right; 
        }
        return dp[s][e]=total;
    }

    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        if (n == 0) return 1;
        return build(1, n);
    }
};