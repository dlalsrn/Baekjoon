#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int storey)
{
    int answer = 0;
    
    while (storey)
    {
        int n = storey % 10;
        storey /= 10;

        if (n == 5)
        {
            if (storey % 10 >= 5)
            {
                answer += 10 - n;
                storey++;
            }
            else
            {
                answer += n;
            }
        }
        else if (10 - n < n)
        {
            answer += 10 - n;
            storey++;
        }
        else
        {
            answer += n;
        }
    }

    return answer;
}
