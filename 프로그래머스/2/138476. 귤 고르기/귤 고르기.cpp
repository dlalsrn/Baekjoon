#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    vector<int> v;

    sort(tangerine.begin(), tangerine.end());
    int cnt = 1;
    int n = tangerine[0];

    for (int i = 1; i < tangerine.size(); i++)
    {
        if (n == tangerine[i])
        {
            cnt++;
        }
        else
        {
            v.push_back(cnt);
            cnt = 1;
            n = tangerine[i];
        }
    }

    v.push_back(cnt);

    sort(v.begin(), v.end(), greater<>());

    cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i];

        if (cnt >= k)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}