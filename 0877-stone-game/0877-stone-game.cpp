class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, auto&nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=nums[i]-solve(i+1,j,nums);
        int right=nums[j]-solve(i,j-1,nums);
        return dp[i][j]=max(left,right);


        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,piles)>=0;
        
    }
};