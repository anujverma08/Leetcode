#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;  // Stores coordinates of rotten oranges
        int freshCount = 0;
        int minutes = 0;
        
        // Step 1: Find all initially rotten oranges & count fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});  // Push rotten orange
                } else if (grid[i][j] == 1) {
                    freshCount++;  // Count fresh oranges
                }
            }
        }

        // Edge case: No fresh oranges, return 0
        if (freshCount == 0) return 0;

        // Step 2: BFS to rot adjacent fresh oranges
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
        
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    
                    // Check valid grid position and if it's a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;  // Rot the orange
                        q.push({nr, nc});  // Add newly rotten orange to queue
                        freshCount--;  // Decrease fresh orange count
                        rotted = true;
                    }
                }
            }
            
            if (rotted) minutes++;  // Increase minutes only if any orange rotted
        }

        // Step 3: Check if any fresh oranges remain
        return (freshCount == 0) ? minutes : -1;
    }
};