#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;


    int gcdA = arrayA[0];
    for (int x : arrayA)
    {
        gcdA = gcd(gcdA, x);
    }

    int gcdB = arrayB[0];
    for (int x : arrayB)
    {
        gcdB = gcd(gcdB, x);
    }

    if (gcdB != 1)
    {
        for (int x : arrayA)
        {
            if (x % gcdB == 0)
            {
                gcdB = 0;
                break;
            }
        }
    }
    else
    {
        gcdB = 0;
    }

    if (gcdA != 1)
    {
        for (int x : arrayB)
        {
            if (x % gcdA == 0)
            {
                gcdA = 0;
                break;
            }
        }
    }
    else
    {
        gcdA = 0;
    }

    answer = max(gcdA, gcdB);

    return answer;
}