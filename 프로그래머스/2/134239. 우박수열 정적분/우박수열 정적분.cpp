// 우박수열 정적분
#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<double> sum;

    int prev = k;
    sum.push_back(0.0f);

    while (k != 1)
    {
        if (k % 2)
        {
            k = k * 3 + 1;
        }
        else
        {
            k /= 2;
        }
        sum.push_back(sum.back() + (k + prev) / 2.0f);
        prev = k;
    }

    for (int i = 0; i < ranges.size(); i++)
    {
        int a = ranges[i][0];
        int b = sum.size() - 1 + ranges[i][1];

        if (a > b)
        {
            answer.push_back(-1.0f);
            continue;
        }

        answer.push_back(sum[b] - sum[a]);
    }

    return answer;
}