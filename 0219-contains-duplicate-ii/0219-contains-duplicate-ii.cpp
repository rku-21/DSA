class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            int num=nums[i];
            if(mp.count(num)){
                if(i-mp[num]<=k)  return true;
            }
            mp[num]=i;
        }
        return false;

        
    }
};