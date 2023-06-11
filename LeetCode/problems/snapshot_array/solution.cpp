class SnapshotArray {
    int cur = 0;
    vector<vector<pair<int, int>>> arr;
public:
    SnapshotArray(int length) : arr(length, vector<pair<int, int>>(1)) {}
    
    void set(int index, int val) {
        if (arr[index].back().first < cur)
            arr[index].push_back({ cur, val });
        else arr[index].back().second =  val;
    }
    
    int snap() {
        return cur++;
    }
    
    int get(int index, int snap_id) {
        return (upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX)) - 1)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */