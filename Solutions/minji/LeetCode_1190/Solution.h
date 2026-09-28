class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> brackets;
        vector<string> letters;
        for(char c: s)
        {
            if(c == '(')
            {
                // letters에 새 공간 만들고 
                // brackets push
                letters.push_back("");
                brackets.push_back(c);
            }
            else if(c == ')')
            {
                int index = letters.size()-1;
                reverse(letters[index].begin(), letters[index].end());

                brackets.pop_back();
                if(brackets.empty() && letters.size() == 1)
                {
                    continue;
                }

                letters[index-1] += letters[index];
                letters.pop_back();
            }
            else
            {
                // 괄호가없는데 문자가 들어올 경우
                if(brackets.empty())
                {
                    // 맨첨일경우
                    if(letters.empty())
                        letters.push_back("");
                }
                // 문자열 맨 마지막 공간에 추가
                int index = letters.size()-1;
                letters[index] += c;
            }

        }
        return letters[0];
    }
};