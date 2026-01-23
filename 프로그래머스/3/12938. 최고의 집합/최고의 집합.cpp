#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
    {
        return { -1 };
    }

    vector<int> answer;

    int a = s / n;
    int b = s % n;

    for (int i = 0; i < n; ++i)
    {
        answer.emplace_back(a + (b ? 1 : 0));

        if (b)
        {
            --b;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}