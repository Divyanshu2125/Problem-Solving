class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        effort[0][0] = 0;

        vector<vector<int>> dire = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto dir: dire)
            {
                int r = curr.first + dir[0];
                int c = curr.second + dir[1];

                if (min(r, c) < 0 || r >= m || c >= n)
                    continue;
                
                int newEffort = max(effort[curr.first][curr.second], abs(heights[r][c] - heights[curr.first][curr.second]));
                
                if (newEffort < effort[r][c])
                {
                    effort[r][c] = newEffort;
                    q.push({r, c});
                }
            }
        }

        return effort[m - 1][n - 1];
    }
};
