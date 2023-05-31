class UndergroundSystem {
    unordered_map<string, unordered_map<string, pair<double, double>>> avg;
    unordered_map<int, pair<string, double>> active;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string u, int t) {
        active[id] = { u, t };
    }
    
    void checkOut(int id, string v, int t) {
        auto [u, s] = active[id];
        auto [sum, cnt] = avg[u][v];
        avg[u][v] = { sum + t - s, cnt + 1 };
    }
    
    double getAverageTime(string u, string v) {
        auto [sum, cnt] = avg[u][v];
        return sum / cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */