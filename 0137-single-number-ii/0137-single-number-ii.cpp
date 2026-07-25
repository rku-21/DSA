class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int bit=0; bit<32; bit++){
            int bitsSum=0;
            for(auto num:nums){
              if(num & (1<<bit)){
                bitsSum+=1;
              }

            }
            int rem=bitsSum%3;
            if(rem){
                ans= ans | (1<<bit);
            }
        }
        return ans;


        
    }
};