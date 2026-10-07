class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        //열
        int m = grid[0].size();
        //행
        int n = grid.size();
        // 열 카운트
        vector<int> mcount(m);
        // 행 카운트
        vector<int> ncount(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            //그리드 순회하면서 서버가 있으면 증가
                if (grid[i][j] == 1) {
                    count++;
                    mcount[j]++;
                    ncount[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            //다시 그리드 순회하면서 전체 서버 수에서 통신을 하지 않는 서버의 수를 뺌
                if (((mcount[j] == 1) && (ncount[i] == 1)) && grid[i][j] == 1) {
                    count--;
                }
            }
        }

        return count;
    }
};