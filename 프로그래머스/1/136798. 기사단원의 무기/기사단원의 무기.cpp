#include <bits/stdc++.h>
using namespace std;

int countDivisor(int n)
{
    int sum = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum++;
            if (n / i != i)
            {
                sum++;
            }
        }
    }

    return sum;
}

int solution(int number, int limit, int power)
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int cnt = countDivisor(i);
        answer += (cnt > limit ? power : cnt);
    }

    return answer;
}