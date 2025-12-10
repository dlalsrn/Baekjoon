// 인사고과
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int solution(vector<vector<int>> scores)
{
    if (scores.size() == 1)
    {
        return 1;
    }

    int answer = 1;

    pi wonho = make_pair(scores[0][0], scores[0][1]);
    vector<pi> v;

    for (int i = 1; i < scores.size(); ++i)
    {
        v.push_back(make_pair(scores[i][0], scores[i][1]));
    }

    sort(v.begin(), v.end(), [](pi& a, pi& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
        }
    );

    int maxAttitude = v[0].first;
    int maxEvaluation = v[0].second;
    for (int i = 0; i < v.size(); ++i)
    {
        if (wonho.first < v[i].first && wonho.second < v[i].second)
        {
            answer = -1;
            break;
        }

        if (v[i].second >= maxEvaluation)
        {
            if (wonho.first + wonho.second < v[i].first + v[i].second)
            {
                answer++;
            }
        }

        maxEvaluation = max(maxEvaluation, v[i].second);
    }

    return answer;
}