// 디펜스 게임
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;
    priority_queue<int> pq;

    for (int x : enemy)
    {
        n -= x;
        pq.push(x);

        if (n < 0)
        {
            if (k)
            {
                k--;
                n += pq.top();
                pq.pop();
            }
            else
            {
                break;
            }
        }

        answer++;
    }

    return answer;
}