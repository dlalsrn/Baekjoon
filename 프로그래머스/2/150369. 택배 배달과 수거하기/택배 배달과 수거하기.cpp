//택배 배달과 수거하기
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    vector<pi> delivery;
    vector<pi> pickup;

    for (int i = 0; i < n; i++)
    {
        if (deliveries[i])
        {
            delivery.push_back(make_pair(i + 1, deliveries[i]));
        }

        if (pickups[i])
        {
            pickup.push_back(make_pair(i + 1, pickups[i]));
        }
    }

    while (!delivery.empty() || !pickup.empty())
    {
        int maxDelivery = (delivery.empty() ? 0 : delivery.back().first);
        int maxPickup = (pickup.empty() ? 0 : pickup.back().first);
        int maxDis = max(maxDelivery, maxPickup);
        answer += maxDis * 2;

        int totalBox = 0;
        while (!delivery.empty() && totalBox < cap)
        {
            int box = min(cap - totalBox, delivery.back().second);
            totalBox += box;
            delivery.back().second -= box;

            if (delivery.back().second == 0)
            {
                delivery.pop_back();
            }
        }

        totalBox = 0;
        while (!pickup.empty() && totalBox < cap)
        {
            int box = min(cap - totalBox, pickup.back().second);
            totalBox += box;
            pickup.back().second -= box;

            if (pickup.back().second == 0)
            {
                pickup.pop_back();
            }
        }
    }

    return answer;
}