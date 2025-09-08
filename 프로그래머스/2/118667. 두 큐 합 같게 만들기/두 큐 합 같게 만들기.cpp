#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    ll sum1 = 0;
    ll sum2 = 0;
    int cnt = 0;
    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 += queue1[i];
        q1.push(queue1[i]);
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }

    for (int i = 0; i < queue1.size() * 3 + 1; i++)
    {
        if (sum1 < sum2)
        {
            sum1 += q2.front();
            q1.push(q2.front());

            sum2 -= q2.front();
            q2.pop();
        }
        else if (sum1 > sum2)
        {
            sum2 += q1.front();
            q2.push(q1.front());

            sum1 -= q1.front();
            q1.pop();
        }
        else
        {
            answer = cnt;
            break;
        }

        cnt++;
    }

    return answer;
}