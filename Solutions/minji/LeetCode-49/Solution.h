class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> us;
        int index = 0;
        for (string str : strs)
        {
            // 원본 임시변수 저장
            string originStr = str;
            // 원본을 알파벳 순으로 정렬
            sort(str.begin(), str.end());
            // 정렬된 문자열이 해시테이블에 존재한다면 result 배열에 추가. 
            if (us.find(str) != us.end())
            {
                result[us[str]].push_back(originStr);
            }
            // 존재하지 않는다면 해시테이블에 새로 추가, 
            // result배열 새 공간 만들기.
            else
            {
                us.insert({ str, index++ });
                result.push_back({ originStr });
            }
        }
        return result;
    }
};