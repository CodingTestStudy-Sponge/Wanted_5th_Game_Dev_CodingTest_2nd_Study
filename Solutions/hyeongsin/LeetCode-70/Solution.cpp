class Solution {
public:
    int climbStairs(int n) {
        vector<int> Fibo;

        Fibo.push_back(1);
        Fibo.push_back(1);

        if(n<2)
        {
            return 1;
        }

        for(int ix=2; ix<=n; ++ix)
        {
            Fibo.push_back(Fibo[ix-1] + Fibo[ix -2]);
        }
        
        return Fibo[n];
    }
};