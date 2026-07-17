class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<32; i++){
            int sum=0;
            for(auto num:nums){
                if(num & (1<<i)){
                    sum+=1;
                }
            }
            int rem=sum%3;
            if(rem==1) ans=ans | (1<<i);

        }

        return ans;
        
    }
};