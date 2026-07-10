class Solution {
public:
 int MOD=1e9+7;
unordered_map<int,vector<int>>mp;
   int dp[10][5001];
    int solve(int d, int n){
        if(n==0) return 1;
        if(dp[d][n]!=-1) return dp[d][n];
        int ans=0;
        for(auto nextd:mp[d]){
            ans=(ans+solve(nextd,n-1))%MOD;
        }
        return dp[d][n]=ans;
    }
    int knightDialer(int n) {
        
        mp[0]={4,6};
        mp[1]={6,8};
        mp[2]={9,7};
        mp[3]={8,4};
        mp[4]={9,3,0};
        mp[5]={};
        mp[6]={7,1,0};
        mp[7]={2,6};
        mp[8]={3,1};
        mp[9]={2,4};

        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<=9 ; i++){
          ans=(ans+solve(i,n-1))%MOD;
        }
        return ans;
            

        
        
    }
};