class ParkingSystem {
    vector<int> cap;
public:
    ParkingSystem(int big, int medium, int small) : cap({ 0, big, medium, small }) {}
    
    bool addCar(int carType) {
        if (!cap[carType])
            return false;
        cap[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */