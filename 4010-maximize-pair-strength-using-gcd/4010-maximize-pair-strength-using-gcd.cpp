class Solution {
public:
    typedef long long ll;
    long long maxPairStrength(vector<int>& nums) {
        ll strength=LLONG_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll mul=1LL*nums[i]*1LL*nums[j];
                ll g=__gcd(nums[i],nums[j]);
                strength=max(strength,mul/(g*g));
            }
        }
        return strength;


        
    }
};