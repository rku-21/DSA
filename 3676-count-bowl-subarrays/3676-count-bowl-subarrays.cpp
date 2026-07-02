class Solution {
public:
    typedef long long ll;
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        ll cnt=0;

        stack<int>st;
        st.push(0);
        for(int r=1; r<n; r++){
            while(!st.empty() && nums[st.top()]<nums[r]){
                int left=st.top();
                st.pop();

                if(r-left+1>=3) cnt++;

            }

            if(!st.empty() && r-st.top()+1>=3) cnt++; 

            st.push(r);





        }


        return cnt;
        
    }
};