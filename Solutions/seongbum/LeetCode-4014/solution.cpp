class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        //두 인덱스 중 최소 사용
        int index = min(prices.size(), discounts.size());
        //할인 적용해서 저장할 double형 벡터 생성
        vector<double> dprices(prices.begin(), prices.end());
        //결과값
        double result = 0;

        //가격과 할인율 내림차순으로 정렬
        std::sort(dprices.rbegin(), dprices.rend());
        std::sort(discounts.rbegin(), discounts.rend());
        

        //할인 적용한걸 double형 배열에 저장
        for(int i = 0; i < index; i++)
        {
            dprices[i] = discount(dprices[i], discounts[i]);
        }

        //할인 적용한 가격 합산
        for(double& elem : dprices)
        {
            result += elem;
        }

        return result;

    }

    double discount(int price, int discount)
    {
        return (price * (100 - discount)) / 100.0;
    }
};