class MyCalendarThree {
public:
    multiset<pair<int,int>>st;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        st.insert({startTime,+1});
        st.insert({endTime,-1});
        auto it=st.begin();
        int ans=1;
        int temp=0;
        while(it!=st.end()){
            if(it->second==1){
                temp++;
                ans=max(ans,temp);
            }
            else {
                temp--;
                ans=max(ans,temp);
            }
            it++;
        }
        return ans;

        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */