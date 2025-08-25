#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int solution(vector<int> arr)
{
    int answer = 0;

    if (arr.size() == 1) answer = arr[0];
    else
    {
        int n1 = arr[0];
        int n2 = arr[1];
        int lcm = n1 * n2 / gcd(n1, n2);

        for (int i = 2; i < arr.size(); i++)
        {
            n1 = lcm;
            n2 = arr[i];
            lcm = n1 * n2 / gcd(n1, n2);
        }

        answer = lcm;
    }

    return answer;
}