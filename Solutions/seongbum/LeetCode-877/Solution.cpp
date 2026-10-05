class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int index = 0;
        int evenindex = 0;
        int oddindex = 0;
        vector<int> result(2);

        //짝수와 홀수 인덱스 합 구하기
        for(int i = 0; i < piles.size(); i++)
        {
            if(i % 2 == 0)
            {
                evenindex += piles[i];
            }
            else
            {
                oddindex += piles[i];
            }
        }

        while(!piles.empty())
        {
            //인덱스 모듈러 연산, 0은 앨리스, 1은 밥의 인덱스로 취급
            index %= 2;
            //짝수 인덱스 합이 홀수 인덱스 합보다 크면 앞에서 가져오고, 아니면 뒤에서 가져오기
            if(evenindex > oddindex)
            {
                result[index] += piles.front();
                piles.erase(piles.begin());
            }
            else
            {
                result[index] += piles.back();
                piles.pop_back();
            }
            index++;
        }
        
        //앨리스가 더 많은 돌을 가져가면 true, 아니면 false 반환
        if(result[0] > result[1])
        {
            return true;
        }
        else return false;
    }
};