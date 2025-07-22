class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>v;
    bool book(int startTime, int endTime) {
        for(auto &p:v){
            if(p.first<endTime && p.second>startTime) return false;
        }
        v.push_back(make_pair(startTime,endTime));
        return true;
    }

    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */