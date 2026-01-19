#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
	priority_queue<int> pq;

    for (int x : works)
    {
        pq.push(x);
    }

    while (!pq.empty() && n)
    {
        int top = pq.top();
        pq.pop();
        --n;
        
        if (top - 1 > 0)
        {
            pq.push(top - 1);
        }
    }

    while (!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}