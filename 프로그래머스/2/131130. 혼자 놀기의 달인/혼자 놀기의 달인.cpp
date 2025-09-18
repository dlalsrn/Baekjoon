// 혼자 놀기의 달인
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int open(vector<int>& cards, vector<bool>& check, int n)
{
    int cnt = 0;

    while (!check[n])
    {
        check[n] = true;
        n = cards[n - 1];
        cnt++;
    }

    return cnt;
}

int solution(vector<int> cards)
{
    int answer = 0;
    int size = cards.size();

    for (int i = 0; i < size; i++)
    {
        int cnt1, cnt2;
        vector<bool> check = vector<bool>(size + 1, false);

        cnt1 = open(cards, check, i + 1);

        for (int j = 0; j < size; j++)
        {
            if (!check[j + 1])
            {
                vector<bool> t(check);
                cnt2 = open(cards, t, j + 1);

                answer = max(answer, cnt1 * cnt2);
            }
        }
    }

    return answer;
}