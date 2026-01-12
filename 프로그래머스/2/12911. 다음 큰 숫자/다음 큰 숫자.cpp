#include <string>
#include <vector>

using namespace std;

int countOne(int n)
{
    int cnt = 0;

    while (n)
    {
        if (n & 1) ++cnt;
		n >>= 1;
    }

    return cnt;
}

int solution(int n)
{
    int answer = 0;

	int cnt = countOne(n);

    for (int i = n + 1;; ++i)
    {
        if (countOne(i) == cnt)
        {
			return i;
        }
	}

    return 0;
}