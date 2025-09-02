#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;
    vector<int> left(10001, 0);
    vector<int> right(10001, 0);
    int leftCnt = 0;
    int rightCnt = 0;

    for (int i = 0; i < topping.size(); i++) // 처음엔 모두 동생꺼
    {
        int n = topping[i];

        if (right[n] == 0) // 없던 토핑이라면
        {
            rightCnt++;
        }
        right[n]++;
    }

    for (int i = 0; i < topping.size(); i++) // 하나씩 철수한테 줌
    {
        int n = topping[i];

        if (left[n] == 0)
        {
            leftCnt++;
        }
        left[n]++;

        if (right[n] == 1)
        {
            rightCnt--;
        }
        right[n]--;

        if (leftCnt == rightCnt)
        {
            answer++;
        }
    }

    return answer;
}