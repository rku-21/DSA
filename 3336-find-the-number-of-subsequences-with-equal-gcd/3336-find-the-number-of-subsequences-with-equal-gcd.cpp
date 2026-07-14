class Solution {
public:
   
    int MOD=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int max_val=*max_element(nums.begin(), nums.end());
        vector<vector<int>>prev(max_val+1,vector<int>(max_val+1,0));

        for(int  i=0; i<=max_val; i++){
            for(int j=0; j<=max_val; j++){
                if(i!=0 && j!=0 && i==j){
                    prev[i][j]=1;
                }
                
            }
        }
       

        for(int idx=n-1; idx>=0; idx--){
            vector<vector<int>>curr(max_val+1,vector<int>(max_val+1,0));
            for(int i=max_val; i>=0; i--){
                for(int j=max_val; j>=0; j--){
                    int skip=prev[i][j];
                    int ans1=prev[__gcd(i,nums[idx])][j];
                    int ans2=prev[i][__gcd(j,nums[idx])];
                    curr[i][j]=(0LL+skip+ans1+ans2)%MOD;
                    
                }
            }
            prev=curr;
        }
        return prev[0][0];


        

        






    }
};