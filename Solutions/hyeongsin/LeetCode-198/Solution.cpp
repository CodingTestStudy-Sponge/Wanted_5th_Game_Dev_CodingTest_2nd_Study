class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[100];
        int answer = 0;

        if(nums.size() == 1)
        {
            return nums[0];
        }
        else if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int ix = 2 ; ix < nums.size(); ++ix)
        {
            dp[ix] = max(dp[ix-1], dp[ix-2] + nums[ix]);
            answer = dp[ix];
        }
        
       return answer;
    }
};