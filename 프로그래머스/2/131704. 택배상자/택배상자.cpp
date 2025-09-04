#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    queue<int> q;
    stack<int> st;

    int mx = *max_element(order.begin(), order.end());
    for (int i = 1; i <= mx; i++)
    {
        q.push(i);
    }

    int index = 0;
    while (!q.empty())
    {
        int n = order[index];

        if (q.front() == n)
        {
            answer++;
            index++;
            q.pop();
        }
        else if (!st.empty() && st.top() == n)
        {
            answer++;
            index++;
            st.pop();
        }
        else
        {
            st.push(q.front());
            q.pop();
        }
    }

    while (!st.empty())
    {
        int n = order[index];
        if (st.top() == n)
        {
            answer++;
            index++;
            st.pop();
        }
        else
        {
            break;
        }
    }

    return answer;
}