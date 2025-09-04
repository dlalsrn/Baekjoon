#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;
vector<bool> numCheck(10000000, false);
vector<bool> visit;

bool IsPrime(int n)
{
    if ((n == 1) || (n != 2 && n % 2 == 0)) // 1이거나 2가 아닌 짝수라면
    {
        return false;
    }

    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void BruteForce(string number, string& numbers)
{
    if (number != "")
    {
        int n = stoi(number);
        if (!numCheck[n])
        {
            numCheck[n] = true;
            if (IsPrime(n))
            {
                answer++;
            }
        }
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            BruteForce(number + numbers[i], numbers);
            visit[i] = false;
        }
    }
}

int solution(string numbers)
{
    visit = vector<bool>(numbers.size(), false);
    BruteForce("", numbers);
    return answer;
}