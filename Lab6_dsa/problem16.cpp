#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Helper structure for A* algorithm
struct Cell {
    int x, y;
    double f, g, h;
    Cell* parent;

    Cell(int x, int y, double g, double h, Cell* parent = nullptr)
        : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}

    bool operator>(const Cell& other) const {
        return f > other.f;
    }
};

class AStar {
private:
    int rows, cols;
    vector<vector<int>> grid;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    AStar(int rows, int cols, const vector<vector<int>>& grid)
        : rows(rows), cols(cols), grid(grid) {}

    // Check if a cell is valid
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
    }

    // Compute heuristic (Manhattan distance)
    double heuristic(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    // A* algorithm
    vector<pair<int, int>> findPath(pair<int, int> start, pair<int, int> end) {
        priority_queue<Cell, vector<Cell>, greater<Cell>> openList;
        vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

        openList.push(Cell(start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second)));

        while (!openList.empty()) {
            Cell current = openList.top();
            openList.pop();

            if (current.x == end.first && current.y == end.second) {
                // Reconstruct path
                vector<pair<int, int>> path;
                Cell* pathNode = &current;
                while (pathNode) {
                    path.emplace_back(pathNode->x, pathNode->y);
                    pathNode = pathNode->parent;
                }
                reverse(path.begin(), path.end());
                return path;
            }

            if (closedList[current.x][current.y]) continue;
            closedList[current.x][current.y] = true;

            for (auto [dx, dy] : directions) {
                int newX = current.x + dx;
                int newY = current.y + dy;

                if (isValid(newX, newY) && !closedList[newX][newY]) {
                    double newG = current.g + 1;
                    double newH = heuristic(newX, newY, end.first, end.second);
                    openList.push(Cell(newX, newY, newG, newH, new Cell(current)));
                }
            }
        }

        // Return empty path if no solution
        return {};
    }
};

int main() {
    // Example Usage: Game Grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
    };

    AStar pathfinder(5, 5, grid);

    pair<int, int> start = {0, 0};
    pair<int, int> end = {4, 4};

    vector<pair<int, int>> path = pathfinder.findPath(start, end);

    // Print the path
    if (!path.empty()) {
        cout << "Path found:\n";
        for (auto [x, y] : path) {
            cout << "(" << x << ", " << y << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
