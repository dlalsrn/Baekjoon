#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int T, num;
    cin >> T;
    double size[10000001];
    size[0] = 0;
    for (int i = 1; i <= 10000000; i++)
        size[i] = (size[i - 1] + log10((double)i));
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        cout << (ll)size[num]+1 << '\n';
    }
    return 0;
}