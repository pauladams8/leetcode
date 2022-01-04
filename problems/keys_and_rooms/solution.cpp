class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        std::unordered_set<int> visited;
        visit(rooms, visited, 0);
        for (int room = 0; room < rooms.size(); room++)
            if (visited.find(room) == visited.end()) return false;
        return true;
    }
private:
    void visit(std::vector<std::vector<int>>& rooms, std::unordered_set<int>& visited, int room) {
        if (visited.find(room) != visited.end()) return;
        visited.insert(room);
        for (int key : rooms[room])
            visit(rooms, visited, key);
    }
};