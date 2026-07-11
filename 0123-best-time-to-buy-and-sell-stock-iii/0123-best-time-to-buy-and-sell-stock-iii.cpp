class Solution {
public:
    // (jay Shree Ram)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
      
        // secMaxProfit store  max profit possible from day i to day n-1
        vector<int>secMaxProfit(n);
        int maxi=prices[n-1];
        secMaxProfit[n-1]=0;
        for(int i=n-2; i>=0; i--){
            secMaxProfit[i]=max(secMaxProfit[i+1],maxi-prices[i]);
            maxi=max(maxi,prices[i]);
        }

        int ans=max(secMaxProfit[0],secMaxProfit[1]);
         int mini=prices[0];
        for(int i=0; i<n-1; i++){
            mini=min(mini,prices[i]);
            int ans1=prices[i]-mini;
            int ans2=secMaxProfit[i+1];
      
            ans=max({ans,ans1,ans2,ans1+ans2});
           
            
           
        }

        return ans<0?0:ans;
        

        
    }
};