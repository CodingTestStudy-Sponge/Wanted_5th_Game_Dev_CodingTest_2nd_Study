class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string var1;
        string var2;

        //첫번째 배열의 두번째 원소 저장하고 시작
        var1 = paths[0][0];
        var2 = paths[0][1];
        for (int i = 1; i < paths.size(); i++)
        {
            //그 다음 배열의 원소 첫번째 원소랑 비교해서 같으면 그 배열의 두번째 원소를 var1에 저장
            if (var2 == paths[i][0])
            {
                var2 = paths[i][1];
                //이전 위치의 배열들의 원소와도 비교하기 위해 인덱스 다시 처음으로 되돌림
                i = 0;
            }
            //두번째 원소가 모든 배열의 첫번째 원소와 다르면 그게 목적지인 것이기 때문에 종료 
        }

        return var2;
    }
};