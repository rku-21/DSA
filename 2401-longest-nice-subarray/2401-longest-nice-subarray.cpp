class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();

        int prefSum=0;
        int ans=INT_MIN;
        int l=0;
        for(int r=0; r<n; r++){
            if(l==r){
                ans=1;
                prefSum+=nums[r];
                continue;
            }
            //  cout<<prefSum<<endl;
            while((prefSum&nums[r])!=0){
                prefSum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            prefSum+=nums[r];
            // cout<<prefSum<<endl;

        }
        return ans;


        
    }
};