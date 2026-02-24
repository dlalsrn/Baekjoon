#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int cnt = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    
    for (int x : scoville)
    {
        pq.push((ll)x);
    }
    
    while (pq.size() >= 2 && pq.top() < K)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
        
        ++cnt;
    }
    
    if (!pq.empty() && pq.top() >= K) return cnt;
    else return -1;
}