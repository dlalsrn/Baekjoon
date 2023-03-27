#include <iostream>
using namespace std;

int N, a, b;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}