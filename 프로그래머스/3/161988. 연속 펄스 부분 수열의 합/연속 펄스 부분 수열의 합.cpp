#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll solution(vector<int> sequence)
{
    ll answer = 0;

    vector<vector<ll>> v = vector<vector<ll>>(2ll, vector<ll>(sequence.size(), 0));
    v[0][0] = static_cast<ll>(sequence[0]);
    v[1][0] = static_cast<ll>(sequence[0] * -1);
    answer = max(v[0][0], v[1][0]);

    for (int i = 1; i < sequence.size(); ++i)
    {
        v[0][i] = max(static_cast<ll>(sequence[i]), v[1][i - 1] + static_cast<ll>(sequence[i]));
        v[1][i] = max(static_cast<ll>(-sequence[i]), v[0][i - 1] + static_cast<ll>(sequence[i] * -1));
        answer = max({ answer, v[0][i], v[1][i] });
    }

    return answer;
}