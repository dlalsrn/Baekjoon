#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int solution(vector<int> stones, int k)
{
    int answer = 200000001;
    priority_queue<pi> pq;

    for (int i = 0; i <= stones.size(); ++i)
    {
        if (i >= k)
        {
            while (!pq.empty() && i - pq.top().second > k)
            {
                pq.pop();
            }

            answer = min(answer, pq.top().first);
        }

        if (i == stones.size())
        {
            break;
        }

        pq.push(make_pair(stones[i], i));
    }

    return answer;
}