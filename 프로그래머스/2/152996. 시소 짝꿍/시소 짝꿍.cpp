#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

long long solution(vector<int> weights)
{
    ll answer = 0;
    vector<ll> cnt(1001, 0ll);
    
    for (int x : weights)
    {
		cnt[x]++;
    }

	sort(weights.begin(), weights.end());
	weights.erase(unique(weights.begin(), weights.end()), weights.end());

    for (int i = 0; i < weights.size(); i++)
    {
		int x = weights[i];
        answer += cnt[x] * (cnt[x] - 1) / 2; // 동일한 무게랑 짝
		answer += (x * 2) % 3 == 0 ? cnt[x] * cnt[x * 2 / 3] : 0; // 2 : 3
        answer += x % 2 == 0 ? cnt[x] * cnt[x / 2] : 0; // 2 : 4
		answer += (x * 3) % 4 == 0 ? cnt[x] * cnt[x * 3 / 4] : 0; // 3 : 4
    }

    return answer;
}