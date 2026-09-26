class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        //결과        
        vector<int> result(nums.size());
        //result 배열 인덱스 감소시키는 용도(맨 오른쪽부터 채우기 위해)
        int position = nums.size() - 1;

        while(left <= right)
        {
            int leftPow = nums[left] * nums[left];
            int rightPow = nums[right] * nums[right];
            if(leftPow > rightPow)
            {
                result[position--] = leftPow;
                left++;
            }
            else
            {
                result[position--] = rightPow;
                right--;
            }
        }
        return result;
    }

};