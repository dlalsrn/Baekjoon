#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int n1 = 0, n2 = 1, n3;

    for (int i = 2; i <= n; i++)
    {
        n3 = (n1 + n2) % 1234567;
        n1 = n2;
        n2 = n3;
    }

    return answer = n3;
}