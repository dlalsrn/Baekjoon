// 유사 칸토어 비트열
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

string str = "11011";
int answer = 0;

void Divide(int n, ll start, ll end, ll left, ll right)
{
    if (end < left || start > right)
    {
        return;
    }
    else if (left <= start && end <= right)
    {
        answer += pow(4, n);
        return;
    }
    else if (n == 1)
    {
        for (ll i = max(left, start) - start; i < min(end - start, right - start + 1); i++)
        {
            if (str[i] == '1')
            {
                answer++;
            }
        }
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
        {
            continue;
        }

        Divide(n - 1, start + pow(5, n - 1) * i, start + pow(5, n - 1) * (i + 1), left, right);
    }
}

int solution(int n, long long l, long long r)
{
    Divide(n, 0ll, pow(5, n), l - 1, r - 1);

    return answer;
}