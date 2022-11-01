#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<pi> v;

int main(void)
{
	int T, x, y;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		v = vector<pi>();
		for (int i = 0; i < 4; i++)
		{
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end());

		if (v[0].first == v[1].first)
		{
			int line1 = v[1].second - v[0].second;
			int line2 = v[2].first - v[0].first;
			int line3 = v[3].first - v[1].first;
			int line4 = v[3].second - v[2].second;
			if (v[0].second == v[2].second && v[2].first == v[3].first && v[1].second == v[3].second && line1 == line2 && line2 == line3 && line3 == line4 && line4 == line1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			double line1 = pow((double)(v[1].first - v[0].first), 2) + pow((double)(v[1].second - v[0].second), 2);
			double line2 = pow((double)(v[2].first - v[0].first), 2) + pow((double)(v[0].second - v[2].second), 2);
			double line3 = pow((double)(v[3].first - v[2].first), 2) + pow((double)(v[3].second - v[2].second), 2);
			double line4 = pow((double)(v[3].first - v[1].first), 2) + pow((double)(v[1].second - v[3].second), 2);
			double cross1 = pow((double)(v[3].first - v[0].first), 2) + pow((double)(v[3].second - v[0].second), 2);
			double cross2 = pow((double)(v[1].first - v[2].first), 2) + pow((double)(v[1].second - v[2].second), 2);
			if (line1 == line2 && line2 == line3 && line3 == line4 && line4 == line1 && cross1 == cross2)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}