#include <iostream>
using namespace std;

int main(void)
{
	int N, M, x, y;
    char c;
	cin >> N >> M;
	int color[3] = { 0 };
	for (int i = 0; i < N; i++)
		cin >> x >> y;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> c;
		if (c == 'R')
			color[0]++;
		else if (c == 'B')
			color[1]++;
		else
			color[2]++;
	}
	if (color[2] % 2 == 1)
		color[1]--;
	if (color[0] > color[1])
		cout << "jhnah917";
	else
		cout << "jhnan917";
	return 0;
}