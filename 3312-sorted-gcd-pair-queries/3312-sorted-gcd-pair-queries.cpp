class Solution {
public:
    typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int n=nums.size();
        int maxi=*max_element(nums.begin(), nums.end());

        vector<int>freq(maxi+1,0);
        vector<ll>gcdPairs(maxi+1,0);

        for(auto num:nums) freq[num]++;

        for(int i=maxi; i>=1; i--){
            int multiple_cnt=0;

            for(int j=i; j<=maxi; j+=i){
                multiple_cnt+=freq[j];

            }
            ll totalPairs=1LL*multiple_cnt*(multiple_cnt-1)/2;

            for(int j=2*i; j<=maxi; j+=i){
                totalPairs-=gcdPairs[j];
            }
            gcdPairs[i]=totalPairs;
        }

        for(int i=1; i<=maxi; i++){
            gcdPairs[i]=gcdPairs[i-1]+gcdPairs[i];
        }

        vector<int>answer;

       for(auto q:queries){
            int ans=0;
            int l=1;
            int r=maxi;
            while(l<=r){
                int mid=(l+r)/2;

                if(gcdPairs[mid]>=q+1){
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            answer.push_back(ans);
       }

       return answer;



        
    }
};