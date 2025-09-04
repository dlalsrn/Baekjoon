#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
using pi = pair<int, int>;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int totalWeight = 0;
    int time = 0;
    queue<pi> q; // weight, time

    for (int i = 0; i < truck_weights.size(); i++)
    {
        if (time >= q.front().second + bridge_length) // 만약 맨 앞 차량이 다리를 모두 건넜다면
        {
            totalWeight -= q.front().first;
            q.pop();
        }

        while (!q.empty() && totalWeight + truck_weights[i] > weight) // 다리에 못 올라간다면
        {
            totalWeight -= q.front().first;
            time += bridge_length - (time - q.front().second) - 1;
            q.pop();
        }
        
        totalWeight += truck_weights[i];
        q.push(make_pair(truck_weights[i], ++time));

        cout << time << ' ' << totalWeight << '\n';
    }

    while (!q.empty())
    {
        time += bridge_length - (time - q.front().second);
        q.pop();
    }

    return answer = time;
}