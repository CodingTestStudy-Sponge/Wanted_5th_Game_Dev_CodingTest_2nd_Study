class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int maxIndex = 0;
        int currentEnd = 0;
        
        for(int ix = 0; ix<nums.size()-1; ++ix)
        {
            maxIndex = max(maxIndex, ix+nums[ix]);

            if(ix == currentEnd)
            {
                ++count;
                currentEnd = maxIndex;
            }
        }
        
        return count;
    }
};