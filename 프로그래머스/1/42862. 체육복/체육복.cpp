#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> v(n, 1);

    for (int i = 0; i < reserve.size(); i++) v[reserve[i] - 1]++;
    for (int i = 0; i < lost.size(); i++) v[lost[i] - 1]--;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 2) // 여벌이 있다면
        {
            if ((i - 1 >= 0) && (v[i - 1] == 0))
            {
                v[i - 1]++;
                v[i]--;
            }
            else if ((i + 1 < n) && (v[i + 1] == 0))
            {
                v[i + 1]++;
                v[i]--;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            answer++;
        }
    }

    return answer;
}