class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 검사할 배열 번호 저장 큐
        queue<pair<int, int>> q;
        // 이미 방문한 칸 담을 해시테이블

        // 가로 요소 개수
        int gridRowLength = grid.size();
        // 세로 요소 개수
        int gridColLength = grid[0].size();
        // 상하좌우
        int colArr[4] = { 0, 0, -1, 1 }; // 가로이동
        int rowArr[4] = { -1, 1, 0, 0 }; // 세로이동
        // 최종 둘레
        int result = 0;

        // 첫 번째 원소를 찾아서 큐에 push. (섬은 1개니까)
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({ i, j });
                    break;
                }

            }
            if (!q.empty()) break;

        }

        while (!q.empty())
        {
            // 현재 x, y
            int x = q.front().first;
            int y = q.front().second;
            // 상하좌우를 검사하여 큐에 삽입.
            for (int k = 0; k < 4; k++)
            {
                int newX = x + rowArr[k]; // 세로 개수
                int newY = y + colArr[k]; // 가로 개수
                // 범위 검사(범위보다 1클때이므로 둘레로 판단)
                if (newX >= gridRowLength || newY >= gridColLength ||
                    newX < 0 || newY < 0)
                {
                    result++;
                }
                // 2일 경우-> 방문 노드 건너뛰기
                else if (grid[newX][newY] == 2 || grid[newX][newY] == 3)
                {
                    continue;
                }
                // 물이면 둘레 길이 ++
                else if (grid[newX][newY] == 0)
                {
                    result++;
                }
                else// 땅이면 큐 삽입
                {
                    q.push({ newX, newY });
                    grid[newX][newY] = 3;
                }

            }
            // 방문 처리 -> grid를 2로 갱신
            grid[x][y] = 2;
            // 로직 끝났으면 현재 위치 pop
            q.pop();
        }
        return result;
    }
};