#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long long n)
{
    bool result = true;

    if (n == 1) result = false;
    else
    {
        for (long long i = 2; i <= (long long)(sqrt(n)); i++)
        {
            if (n % i == 0)
            {
                result = false;
                break;
            }
        }
    }

    return result;
}

int solution(int n, int k)
{
    int answer = 0;
    string s = "";

    while (n)
    {
        s = to_string(n % k) + s;
        n /= k;
    }
    cout << s << '\n';
    string t = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            t += s[i];

            if (i == s.size() - 1)
            {
                if (!t.empty() && IsPrime(stoll(t)))
                {
                    answer++;
                }
            }
        }
        else
        {
            if (!t.empty() && IsPrime(stoll(t)))
            {
                answer++;
            }
            t = "";
        }
    }

    return answer;
}