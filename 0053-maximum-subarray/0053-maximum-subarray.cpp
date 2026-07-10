class Solution {
public:
    
    int solve(auto&nums, int l, int r){
        if(l==r) return nums[l];

        int mid=(l+r)/2;
        int lss=solve(nums,l,mid);
        int rss=solve(nums,mid+1,r);
        int max_right=0;
        int max_left=nums[mid];
        int sum=nums[mid];
        for(int i=mid-1; i>=l; i--){
            sum+=nums[i];
            max_left=max(sum,max_left);

        }
        sum=0;
        for(int i=mid+1; i<=r; i++){
            sum+=nums[i];
            max_right=max(sum,max_right);
        }
        return max({max_right+max_left, lss,rss});




    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1); // what is max subarray sum of nums , with left pointer at 0 , right pointer at n i.e ==> len is n
        
    }
};