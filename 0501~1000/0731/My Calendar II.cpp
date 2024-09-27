class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto event : book2){
            int st = event.first, ed = event.second;
            if(st >= end)
                break;
            if((start >= st && start < ed) || (end < ed && end >= st) || (start < st && end >= ed))
                return false;
        }
        for(auto event : book1){
            int st = event.first, ed = event.second;
            if(st >= end)
                break;
            if((start >= st && start < ed) || (end < ed && end >= st) || (start < st && end >= ed)){
                book2.insert({max(start, st), min(end, ed)});
            }
        }
        book1.insert({start, end});
        return true;
    }
private:
    set<pair<int, int>> book1, book2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
