class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //bfs를 위해 큐 선언
        std::queue<std::pair<int, int>> que;
        
        //행, 열 사이즈
        int row = image.size();
        int col = image[0].size();

        //새로운 좌표 검사를 위해 배열 선언, (-1,0), (1, 0), (0, -1), (0, 1) 이 상하좌우를 나타냄
        int rowArray[4] = {-1, 1, 0, 0};
        int colArray[4] = {0, 0, -1, 1};

        //큐에 들어간 상태를 저장할 2차원 벡터, 기본값 false로 지정
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        //큐에 시작 픽셀 넣기
        que.push({sr, sc});

        //시작 픽셀이 큐에 들어갔으므로 true true;
        visited[sr][sc] = true;
        
        //시작 픽셀의 색 저장
        int beforeColor = image[sr][sc];

        while(!que.empty())
        {
		        //큐에서 좌표 꺼내기
            int querow = que.front().first;
            int quecol = que.front().second;
            
            que.pop();
            
            //Flood Fill 실행(컬러 변환)
            image[querow][quecol] = color; 

            for(int i = 0; i < 4; i++)
            {
		            //상하좌우 새로운 좌표 만들기
                int newRow = querow + rowArray[i];
                int newCol = quecol + colArray[i];

                //새 좌표가 범위 밖이면 건너뛰기
                if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col) continue;
                
                //이미 방문했거나 원래 색이랑 다르면(시작 픽셀과 동일한 색상에만 변환 진행해야 함) 건너뛰기
                if(visited[newRow][newCol] == true || image[newRow][newCol] != beforeColor) continue;

                //여기까지 왔으면 큐에 push
                que.push({newRow, newCol});
                
                //큐에 들어간 상태 처리
                visited[newRow][newCol] = true;
            }
        }
				//모든 처리 이후 이미지 반환
        return image;

    }
};