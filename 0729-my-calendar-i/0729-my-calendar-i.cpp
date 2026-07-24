class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {

        
    }
    
    bool book(int startTime, int endTime) {

        auto next=st.lower_bound({startTime,0});

        if(next!=st.end() &&  next->first<endTime) return false;

        if(next!=st.begin()){
            auto prev=std::prev(next);

            if(startTime<prev->second) return false;

        }

        st.insert({startTime,endTime});
        return true;
       
       


        




        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */