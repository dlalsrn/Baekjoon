#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<pair<int, int>> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        q.push(make_pair(progresses[i], speeds[i]));
    }

    int day = 0;
    int cnt = 0;
    day = ceil((100 - q.front().first) / static_cast<float>(q.front().second));

    while (!q.empty())
    {
        auto [rate, speed] = q.front();
        q.pop();

        if (rate + speed * day >= 100)
        {
            cnt++;
            continue;
        }
        else
        {
            answer.push_back(cnt);
            cnt = 1;
            day = ceil((100 - rate) / static_cast<float>(speed));
        }
    }

    answer.push_back(cnt);

    return answer;
}