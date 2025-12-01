#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll solution(int n, vector<int> times)
{
    ll left = 1;
    ll right = 1'000'000'000'000'000'000;

    while (left < right)
    {
        ll sum = 0;
        ll mid = (left + right) / 2;
        for (int x : times)
        {
            sum += mid / x;
        }

        if (sum >= n)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return right;
}