class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<ll>prefSum(n),prefNonZeroCnt(n), prefX(n),powt(n+1);

        powt[0]=1;
        for(int i=1; i<=n; i++){
            powt[i]=(powt[i-1]*10)%MOD;
        }

        for(int i=0; i<n; i++){
            int d=s[i]-'0';

            if(i>0){
                prefSum[i]=prefSum[i-1];
                prefNonZeroCnt[i]=prefNonZeroCnt[i-1];
                prefX[i]=prefX[i-1];
            }

            if(d!=0){
                prefSum[i]+=d;
                prefNonZeroCnt[i]+=1;
                prefX[i]=(prefX[i]*10+d)%MOD;
            }
        }


        vector<int>ans;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];

            ll sum=prefSum[r]-(l>0?prefSum[l-1]:0);
            int cnt=prefNonZeroCnt[r]-(l>0?prefNonZeroCnt[l-1]:0);
            ll x=0;
            if(cnt>0){
                ll left=(l>0?prefX[l-1]:0);
                x=(prefX[r]-(left*powt[cnt]%MOD)+MOD)%MOD;
                

            }
           
            ll answer=(x*sum)%MOD;
            ans.push_back(answer);

            
        }


        return ans;

        
    }
};