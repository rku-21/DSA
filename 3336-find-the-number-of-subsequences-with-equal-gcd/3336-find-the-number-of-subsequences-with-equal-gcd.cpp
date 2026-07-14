class Solution {
public:
    int dp[201][201][201];
    int MOD=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int max_val=*max_element(nums.begin(), nums.end());
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=max_val; i++){
            for(int j=0; j<=max_val; j++){
                if(i!=0 && j!=0 && i==j){
                    dp[n][i][j]=1;
                }
                else dp[n][i][j]=0;
            }
        }

        for(int idx=n-1; idx>=0; idx--){
            for(int i=max_val; i>=0; i--){
                for(int j=max_val; j>=0; j--){
                    int skip=dp[idx+1][i][j];
                    int ans1=dp[idx+1][__gcd(i,nums[idx])][j];
                    int ans2=dp[idx+1][i][__gcd(j,nums[idx])];
                    dp[idx][i][j]=(0LL+skip+ans1+ans2)%MOD;


                }
            }
        }
        return dp[0][0][0];


        

        






    }
};