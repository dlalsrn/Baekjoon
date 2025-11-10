// 이중우선순위큐
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
unordered_map<int, int> unmap;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
		istringstream iss(operations[i]);

        char cmd;
        int val;

        iss >> cmd >> val;

        if (cmd == 'I')
        {
            max_pq.push(val);
            min_pq.push(val);
            unmap[val]++;
        }
        else
        {
            if (val > 0) // 최댓값 삭제
            {
                while (!max_pq.empty() && !unmap[max_pq.top()])
                {
                    max_pq.pop();
                }

                if (!max_pq.empty())
                {
                    unmap[max_pq.top()]--;
                    max_pq.pop();
                }
            }
            else // 최솟값 삭제
            {
                while (!min_pq.empty() && !unmap[min_pq.top()])
                {
                    min_pq.pop();
                }

                if (!min_pq.empty())
                {
                    unmap[min_pq.top()]--;
                    min_pq.pop();
                }
            }
        }
    }

    while (!max_pq.empty() && !unmap[max_pq.top()])
    {
        max_pq.pop();
    }

    while (!min_pq.empty() && !unmap[min_pq.top()])
    {
        min_pq.pop();
    }

    if (max_pq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }

    return answer;
}