class Solution {
public:
    typedef long long ll ;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int>freq(maxi+1,0);

        vector<ll>gcdCntPairs(maxi+1,0);

        for(int num:nums){
            freq[num]++;
        }

        for(int i=maxi; i>=1; i--){
            int multiples_cnt=0;
            for(int j=i; j<=maxi; j+=i){
                multiples_cnt+=freq[j];
            }

            ll totalPairs=1LL*multiples_cnt*(multiples_cnt-1)/2;

            for(int j=2*i; j<=maxi; j+=i){
                totalPairs-=gcdCntPairs[j];
            }
            gcdCntPairs[i]=totalPairs;
        }

          for(int i=1; i<=maxi; i++){
            gcdCntPairs[i]+=gcdCntPairs[i-1];
        }

        vector<int>ans;

       
        for(auto q:queries){

            int l=1;
            int r=maxi;
            int tmp=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(gcdCntPairs[mid]>q){
                    tmp=mid;
                    r=mid-1;
                }
                else l=mid+1;

            }
            ans.push_back(tmp);

           
        }

        return ans;
        
    }
};