class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>vis(nums[n-1]+1,0);
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]=1;
        }

        int ans=1;
        for(int i=0; i<n; i++){

           int temp=1;

           long long a=nums[i];
           if(vis[a]==1 || a>1000) continue;
           vis[a]=1;
           while(mp.count(a*a)){
               temp++;
               a=a*a;
              if(a<vis.size()) vis[a]=1;
           }
           ans=max(ans,temp);
        }

        if(ans<2) return -1;
        return ans;



        
    }
};