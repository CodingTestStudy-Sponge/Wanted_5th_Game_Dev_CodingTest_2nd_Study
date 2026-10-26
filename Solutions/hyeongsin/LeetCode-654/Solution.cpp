class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> specialNums;
        vector<int> answer;
        
        //키 값이 존재하는지 존재한다면 2개이기때문에 push.
        for(int ix = 0; ix < nums.size(); ++ix)
        {
            auto iterator = specialNums.find(nums[ix]);
            if(iterator != specialNums.end())
            {
                if(iterator->first == nums[ix])
                {
                    answer.push_back(nums[ix]);
                }
            }
            specialNums[nums[ix]] = ix;
        }

        for(int ix = 0; ix < nums.size(); ++ix)
        {
            //존재 여부만 체크하면 됨.
            //ix+1로 놓은 이유는 인덱스가 곧 이전에 넣어둔 키 값과 같아야지 모든 수가 존재하               는 것.
            auto iter = specialNums.find(ix+1);
            if(iter != specialNums.end())
            {
                continue;
            }
            else
            {
                answer.push_back(ix+1);
            }
            
        }

        return answer;
    }
};