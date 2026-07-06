class Solution {
public:
    typedef long long ll;
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        ll ans=0;
        
        // even
        int j=0;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                while(j<n && target[j]%2!=0){
                    j++;
                }
                if(target[j]>nums[i]){
                    ans+=(target[j]-nums[i])/2;

                }
                j++;

            }


        }
        j=0;
        for(int i=0; i<n; i++){
            if(nums[i]&1){
                while(j<n && target[j]%2==0){
                    j++;
                }
                if(target[j]>nums[i]){
                    ans+=(target[j]-nums[i])/2;

                }
                j++;

            }


        }

        return ans;

        
    }
};