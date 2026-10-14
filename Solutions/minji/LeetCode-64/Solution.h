class Solution {
public:
    int Encode(int x, int y)
    {
        return x * 31 + y;
    }
    int minPathSum(vector<vector<int>>& grid) {
        // 비용 계산용 2차원벡터
        vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), 100000000));
        // 방문 노드
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        visited[0][0] = true;
        cost[0][0] = grid[0][0];

        //int x = 0;
        //int y = 0;
        // 좌 우 
        int arrowX[] = { -1, 1 };
        // 상 하 
        int arrowY[] = { -1, 1 };
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[0].size(); x++)
            {
                // 상
                if (y + arrowY[0] >= 0 && !visited[y + arrowY[0]][x])
                    q.push(make_pair(y + arrowY[0], x));

                // 하
                if (y + arrowY[1] < grid.size() && !visited[y + arrowY[1]][x])
                    q.push(make_pair(y + arrowY[1], x));

                // 좌
                if (x + arrowX[0] >= 0 && !visited[y][x + arrowX[0]])
                    q.push(make_pair(y, x + arrowX[0]));

                // 으ㅜ
                if (x + arrowX[1] < grid[0].size() && !visited[y][x + arrowX[1]])
                    q.push(make_pair(y, x + arrowX[1]));

                // 방문노드처리. 
                visited[y][x] = true;
                // 큐에서 빼 온 후 경로를 계산하여 배열을 업데이트한다. 
                // 현재 노드 + 최소 비용이 원래 현재노드비용보다 작으면 업데이트. 

                while (!q.empty())
                {
                    if (grid[q.front().first][q.front().second] + cost[y][x] < cost[q.front().first][q.front().second])
                    {
                        cost[q.front().first][q.front().second] = grid[q.front().first][q.front().second] + cost[y][x];
                    }
                    q.pop();
                }
            }
        }

        return cost[grid.size() - 1][grid[0].size() - 1];
    }
};