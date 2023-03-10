class Event {
public:
    int start;
    int end;
    Event* earlier;
    Event* later;
    Event(int start, int end) : start(start), end(end), earlier(nullptr), later(nullptr) {}
    ~Event() {
        delete earlier;
        delete later;
    }
};

class MyCalendar {
    Event* root;
public:
    MyCalendar() : root(nullptr) {}
    ~MyCalendar() {
        delete root;
    }
    
    bool book(int start, int end) {
        Event** ev = &root;
        while (*ev) {
            if (end <= (*ev)->start)
                ev = &(*ev)->earlier;
            else if (start >= (*ev)->end)
                ev = &(*ev)->later;
            else return false;
        }
        *ev = new Event(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */