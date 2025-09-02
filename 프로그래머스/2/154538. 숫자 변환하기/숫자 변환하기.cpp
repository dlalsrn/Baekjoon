#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
using pi = pair<int, int>;

int solution(int x, int y, int n)
{
    const int MAX = 1'000'001;
    int answer = MAX;
    vector<bool> check(3'000'001, false);
    queue<pi> q;
    
    q.push(make_pair(x, 0));
    check[x] = true;

    while (!q.empty())
    {
        auto [sum, cnt] = q.front();
        q.pop();

        if (sum == y)
        {
            answer = min(answer, cnt);
            continue;
        }
        else if (sum > y)
        {
            continue;
        }

        if (!check[sum + n])
        {
            check[sum + n] = true;
            q.push(make_pair(sum + n, cnt + 1));
        }

        if (!check[sum * 2])
        {
            check[sum * 2] = true;
            q.push(make_pair(sum * 2, cnt + 1));
        }

        if (!check[sum * 3])
        {
            check[sum * 3] = true;
            q.push(make_pair(sum * 3, cnt + 1));
        }
    }

    return answer == MAX ? -1 : answer;
}