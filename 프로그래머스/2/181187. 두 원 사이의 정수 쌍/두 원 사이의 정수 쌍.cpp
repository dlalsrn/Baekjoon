// 두 원 사이의 정수 쌍
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

long long solution(int r1, int r2)
{
    long long answer = 0;
    if (r1 > r2)
    {
        swap(r1, r2);
    }

    for (ll i = 0; i <= r2; i++)
    {
        if (i <= r1)
        {
            double y1 = sqrt((ll)r1 * (ll)r1 - i * i);
            double y2 = sqrt((ll)r2 * (ll)r2 - i * i);

            if (y1 > y2)
            {
                swap(y1, y2);
            }

            ll cnt = floor(y2) - ceil(y1) + 1;

            if (i > 0)
            {
                cnt *= 2;
            }

            if (i == r1)
            {
                cnt--;
            }

            answer += cnt * 2;
        }
        else
        {
            double y2 = sqrt((ll)r2 * (ll)r2 - i * i);
            ll cnt = floor(y2) - ceil(-y2) + 1;
            answer += cnt * 2;
        }
    }

    return answer;
}