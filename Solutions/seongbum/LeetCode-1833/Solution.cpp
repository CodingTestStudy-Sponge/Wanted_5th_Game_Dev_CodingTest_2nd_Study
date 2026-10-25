class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        int result = 0; 
        for(int elem : costs)
        {
            //costs에서 최대 코스트를 구하고, 이걸 새로운 배열의 크기로 사용
            maxCost = max(maxCost, elem);
        }    

        //costs의 원소 값이 몇개 있는지를 셀 카운트 배열 선언
        vector<int> count(maxCost + 1, 0);
        for(int elem : costs)
        {
            //costs 순회하면서 원소가 있으면 그 인덱스의 값 1 증가
            count[elem]++;
        }

        for(int price = 1; price <= maxCost; price++)
        {
            //현재 가지고 있는 돈이 가격보다 적으면 돈이 부족한 것이므로 for문 종료
            if(coins < price)
            {
                break;
            }

            //costs에 없는 값이 있으면 count[price]가 0이기 때문에 continue
            if(count[price] == 0) continue;
            //현재 cost에서 있는 같은 가격의 아이스크림의 재고와 (현재 가진 돈 / 가격) = 현재 살수 있는 아이스크림 개수 중 더 적은걸 선택 
            int buy = min(count[price], coins / price);
            //현재 산 아이스크림 개수 더하기
            result += buy;
            //현재 가진 돈에서 구매한 개수 * 가격만큼 빼기 
            coins -= buy * price;
        }
    
        return result;
    }
};