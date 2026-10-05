class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> findChar;
        int maxResult = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 중복값이 나왔다면 값 갱신
            if (findChar.find(s[i]) != findChar.end())
            {
                // count보다 중복값의 거리가 더 멀다면 이전에 검사했던 중복값임 -> 업데이트
                if (i - findChar[s[i]] > count)
                {
                    // 중복값 인덱스 갱신
                    findChar[s[i]] = i;
                    count++;
                    // 맨 마지막 인덱스면 max 갱신
                    if (i >= s.size() - 1)
                    {
                        // 맥스값 갱신
                        if (maxResult < count)
                        {
                            maxResult = count;
                        }
                    }
                    continue;
                }
                // 맥스값 갱신
                if (maxResult < count)
                {
                    maxResult = count;
                    cout << count << " ";
                }
                // 카운트 갱신
                count = i - findChar[s[i]];

                // 중복값 인덱스 갱신
                findChar[s[i]] = i;
            }
            else
            {
                findChar.insert({ s[i], i });
                count++;
                cout << count << " ";
                // c가 마지막 문자라면 맥스값 갱신
                if (i >= s.size() - 1)
                {
                    // 맥스값 갱신
                    if (maxResult < count)
                    {
                        maxResult = count;
                    }
                }
            }
        }

        for (auto it = findChar.begin(); it != findChar.end(); it++)
            cout << it->first << " " << it->second << "\n";
        return maxResult;
    }
};