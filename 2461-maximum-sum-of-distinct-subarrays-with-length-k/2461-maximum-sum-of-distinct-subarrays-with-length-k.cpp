class Solution {
public:
    typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int>freq;
        ll sum=0;
        ll max_sum=INT_MIN;
        int l=0;
        for(int r=0; r<n; r++){
            freq[nums[r]]++;
            sum+=nums[r];
            while(freq[nums[r]]>1 || r-l+1>k){
                freq[nums[l]]--;
                sum-=nums[l];
                if(freq[nums[l]]==0) freq.erase(nums[l]);
                l++;
            }
            if(r-l+1==k){
                max_sum=max(max_sum,sum);
            }



        }

        return max_sum==INT_MIN?0:max_sum;





        
    }
};