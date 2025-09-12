#include <cmath>
using namespace std;
using ll = long long;

ll solution(int w, int h)
{
    ll answer = static_cast<ll>(w) * static_cast<ll>(h);
    ll cnt = 0;
    double slope = h / static_cast<double>(w);

    for (int i = 1; i <= w; i++)
    {
        double start = static_cast<double>(h) * (i - 1) / w;
        double end = static_cast<double>(h) * i / w;
        cnt += static_cast<ll>(ceil(end)) - static_cast<ll>(floor(start));
    }

    answer -= cnt;

    return answer;
}