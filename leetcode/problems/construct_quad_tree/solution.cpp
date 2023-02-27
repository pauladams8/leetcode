/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }

    Node* construct(vector<vector<int>>& grid, int startRow, int startCol, int endRow, int endCol) {
        if (startRow >= endRow || startCol >= endCol)
            return new Node(grid[startRow][startCol], true);
        Node *quad = new Node();
        quad->isLeaf = false;
        quad->topLeft = construct(grid, startRow, startCol, (startRow + endRow) / 2, (startCol + endCol) / 2);
        quad->topRight = construct(grid, startRow, (startCol + endCol) / 2 + 1, (startRow + endRow) / 2, endCol);
        quad->bottomLeft = construct(grid, (startRow + endRow) / 2 + 1, startCol, endRow, (startCol + endCol) / 2);
        quad->bottomRight = construct(grid, (startRow + endRow) / 2 + 1, (startCol + endCol) / 2 + 1, endRow, endCol);
        vector<Node*> quadrants = { quad->topLeft, quad->topRight, quad->bottomLeft, quad->bottomRight };
        for (Node *quadrant : quadrants)
            if (!quadrant->isLeaf)
                return quad;
        for (int i = 1; i < 4; i++)
            if (quadrants[i]->val != quadrants[0]->val)
                return quad;
        return new Node(quadrants[0]->val, true);
    }
};