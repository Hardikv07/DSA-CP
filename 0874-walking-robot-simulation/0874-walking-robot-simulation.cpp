class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions represent North, East, South, West (in that order)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;  // Start facing North (0)
        int x = 0, y = 0;  // Start position
        int ans = 0;       // Maximum distance from the origin

        // Store obstacles in a set for fast lookup
        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        for (auto it : commands) {
            if (it == -1) { // Turn right
                dirIndex = (dirIndex + 1) % 4;
            } else if (it == -2) { // Turn left
                dirIndex = (dirIndex + 3) % 4;
            } else { // Move forward
                for (int step = 0; step < it; step++) {
                    // Calculate the next position
                    int nx = x + directions[dirIndex].first;
                    int ny = y + directions[dirIndex].second;

                    // If the next position is an obstacle, stop moving in this direction
                    if (obstacleSet.find({nx, ny}) != obstacleSet.end()) {
                        break;
                    }

                    // Move to the next position if no obstacle
                    x = nx;
                    y = ny;

                    // Update the maximum distance
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};
