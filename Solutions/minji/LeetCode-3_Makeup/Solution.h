class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 주어진 문자를 아스키코드 인덱스로 대응하기 위해 256의 배열을 선언. 
        // 방문한 문자의 인덱스를 값으로 넣는다. 
        // 방문하지 않은 문자 인덱스 -> -1로 표시.
        vector<int> lastIndex(256, -1);
        // 현재 부분 문자열의 시작 인덱스
        int left = 0;
        // 최대 길이
        int maxResult = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            // 현재 인덱스 문자 
            unsigned char c = s[i];

            // 현재 문자가 left보다 크다면(시작 인덱스보다 크다)
            // 중복이라는 말임
            // 현재 인덱스부터 시작해야 하기 때문에 0부터시작이니까 1을더한다. 
            left = max(left, lastIndex[c] + 1);

            // 문자가 최근에 등장했던 위치를 업데이트. 
            lastIndex[c] = i;

            // 길이 최댓값 갱신. 
            // 현재인덱스 - left(중복나온자리) + 1(0부터 시작하니까 더해주기)
            maxResult = max(maxResult, i - left + 1);
        }
        return maxResult;
    }
};