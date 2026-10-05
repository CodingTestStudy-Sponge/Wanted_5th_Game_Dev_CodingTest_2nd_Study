class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];

        for(int ix = 0; ix<nums.size()-1; ++ix)
        {
            maxIndex = max(maxIndex, ix+nums[ix]);
            if(maxIndex  < ix+1)
            {
                return false;
            }
            
        }

        return true;
    }
};