class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //주식을 가지고 있는 상태 (초기값에 주식을 산거니까 음수로 넣음)
        int have = -prices[0];
        //주식을 안가지고 있는 상태는 0으로 시작
        int nothave = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            //nothave 상태를 계산할 때 have 상태 계산한 값은 오늘의 have 값임
            int prevHave = have;

            //주식을 들고 있는 상태에서의 최대 값 계산(현재 값이랑 주식이 없는 상태에서 주식을 산 값을 비교)
            have = max(have, nothave - prices[i]);

            //주식을 안들고 있는 상태에서의 최대 값 계산(현재 값과 주식이 있는 상태에서 주식을 판 값을 비교)
            nothave = max(nothave, prevHave + prices[i] - fee);
        }

        //nothave 리턴(have상태를 리턴한다는건 주식을 사놓고 안판 상태의 값을 리턴하는 거니까 nothave보다 높을 수 없음)
        return nothave;
    }
};