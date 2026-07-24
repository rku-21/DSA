class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(), nums.end());

        int size=1;
        while(size<=maxi){
            size<<=1;
        }
        vector<int>st1(size,false);
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st1[nums[i]^nums[j]]=true;
            }
        }

        vector<int>st2(size,false);
        for(int i=0; i<size; i++){
            if(st1[i]==true){
                for(int j=0; j<n; j++){
                    st2[nums[j]^i]=true;
                }
            }
        }

        int cnt=0;
        for(int i=0; i<size; i++){
            if(st2[i]) cnt++;
        }
        return cnt;


        
    }
};