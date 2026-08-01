class Solution {
public:
    int solve(int i, int j, auto&nums){
        if(i>j) return 0;

        int left=nums[i]-solve(i+1,j,nums);
        int right=nums[j]-solve(i,j-1,nums);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();

        return solve(0,n-1,nums)>=0;
        
    }
};