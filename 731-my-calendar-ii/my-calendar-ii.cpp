class MyCalendarTwo {
public:
    vector<pair<int,int>>doubleBooking;
    vector<pair<int,int>>booking;
    bool alreadyBooked(int start1,int end1,int start2,int end2){
        return max(start1,start2)<min(end1,end2);
    }
    pair<int,int>findCommonRegion(int start1,int end1,int start2,int end2){
        return {max(start1,start2),min(end1,end2)};
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto booked:doubleBooking){
            if(alreadyBooked(booked.first,booked.second,startTime,endTime)){
                return false;
            }
        }
        for(auto booked:booking){
            if(alreadyBooked(booked.first,booked.second,startTime,endTime)){
                doubleBooking.push_back(findCommonRegion(booked.first,booked.second,startTime,endTime));
            }
        }
        booking.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */