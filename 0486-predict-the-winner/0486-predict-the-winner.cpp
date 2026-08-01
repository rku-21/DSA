class Solution {
public:
    int solve(int i, int j, auto&nums){
        if(i>j) return 0;

        int left=nums[i]-solve(i+1,j,nums);
        int right=nums[j]-solve(i,j-1,nums);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // return solve(0,n-1,nums)>=0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i>j){
                    dp[i][j]=0;
                    continue;
                }
                int left=nums[i]-solve(i+1,j,nums);
                int right=nums[j]-solve(i,j-1,nums);
                dp[i][j]=max(left,right);

            }
        }
        return dp[0][n-1]>=0;
        
    }
};