#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

ll solution(int k, int d)
{
    ll answer = 0;

    for (ll i = 0; i <= d; i += k)
    {
        ll y = static_cast<ll>(floor(sqrt((ll)d * d - i * i))) / k;
        answer += y + 1;
    }

    return answer;
}