class Solution {
public:
    int countVowelStrings(int n) {
        //조합 공식 사용
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};