#include <string>
#include <vector>

using namespace std;

long long solution(int n)
{
    long long answer = 0;
    int n1 = 1;
    int n2 = 2;

    if (n <= 2) answer = n;
    else
    {
        int n1 = 1;
        int n2 = 2;
        int n3;

        for (int i = 3; i <= n; i++)
        {
            n3 = (n1 + n2) % 1234567;
            n1 = n2;
            n2 = n3;
        }

        answer = n3;
    }

    return answer;
}