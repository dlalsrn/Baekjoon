using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n)
    {
        if (n & 1)
        {
            ++ans;
            --n;
        }
        else
        {
            n >>= 1;
        }
    }

    return ans;
}