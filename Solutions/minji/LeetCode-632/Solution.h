class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 모든 배열을 1차원으로 담는 배열
        vector<pair<int, int>> allRange;
        // 배열이 모두 들어왔는지 확인
        int arrSize = nums.size();
        vector<int> count(arrSize, 0);

        for (int i = 0; i < arrSize; i++)
        {
            for (int num : nums[i])
            {
                // 현재 값, 배열 번호로 추가. 
                allRange.push_back(make_pair(num, i));
            }
        }
        // 다 넣었으면 배열 소트
        sort(allRange.begin(), allRange.end());

        int left = 0;
        int included = 0;
        long long minLength = LONG_MAX;
        vector<int> result(2, 0);
        // 검사 시작
        // k개의 배열이 하나씩 다 들어온 것을 체크하는 변수.
        for (int i = 0; i < allRange.size(); i++)
        {
            int index = allRange[i].second;

            // 처음 들어온 배열이면 included 증가
            if (count[index] == 0)
            {
                included++;
            }
            count[index]++;

            while (included == arrSize)
            {
                // 갱신
                int length = allRange[i].first - allRange[left].first;
                if (length < minLength)
                {
                    minLength = length;
                    result[0] = allRange[left].first;
                    result[1] = allRange[i].first;
                }
                // 한 칸씩 밀며 검사하기 위해
                // left의 배열 번호 카운트를 감소시킨다.
                int leftIndex = allRange[left].second;
                count[leftIndex]--;
                // left해당 배열이 완전히 빠졌다면 총 배열 개수도 --
                if (count[leftIndex] == 0)
                    included--;
                // 다음 left이동
                left++;
            }
        }
        return result;
    }
};