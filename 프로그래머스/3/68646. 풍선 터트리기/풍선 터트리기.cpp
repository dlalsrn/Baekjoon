#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int solution(vector<int> a)
{
    const int MIN_NUM = -1'000'000'000;
    const int MAX_NUM = 1'000'000'000;

    if (a.size() <= 2)
    {
        return a.size();
    }

    int answer = 0;
    vector<pi> v = vector<pi>(a.size());

    int left_mx = MAX_NUM + 1;
    int right_mx = MAX_NUM + 1;
    for (int i = 0; i < a.size(); ++i)
    {
        v[i].first = left_mx;
        left_mx = min(left_mx, a[i]);

        v[a.size() - i - 1].second = right_mx;
        right_mx = min(right_mx, a[a.size() - 1 - i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (v[i].first > a[i] || a[i] < v[i].second)
        {
            answer++;
        }
    }

    return answer;
}