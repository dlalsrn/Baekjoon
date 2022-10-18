#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
	queue <int> qu;
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		qu.push(i);

	for (; qu.size() != 1;)
	{
		qu.pop();
		qu.push(qu.front());
		qu.pop();
	}
	cout << qu.front();
    return 0;
}