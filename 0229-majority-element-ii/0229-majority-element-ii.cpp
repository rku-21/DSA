class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candi1=0,candi2=0,vote1=0,vote2=0;

        for(int i=0; i<n; i++){
            if(nums[i]==candi1) vote1++;
            else if(nums[i]==candi2) vote2++;
            else if(vote1==0){
                candi1=nums[i];
                vote1++;
            }
            else if(vote2==0){
                candi2=nums[i];
                vote2++;
            }
            else {
                vote1--;
                vote2--;
            }
        }
        vector<int>ans;
        vote1=vote2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==candi1) vote1++;
            else if(nums[i]==candi2) vote2++;
        }
        if(vote1>n/3) ans.push_back(candi1);
        if(vote2>n/3) ans.push_back(candi2);

        return ans;


    }
};