class MyCalendarTwo {
public:
   map<int,int>timeline;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;

        int booked=0;
        for(auto & [time, change]: timeline){
            booked+=change;

            if(booked>=3){
                // Rollback the changes and reject the booking 
                timeline[startTime]--;
                timeline[endTime]++;


                
                return false;
                
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */