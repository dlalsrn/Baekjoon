#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	int remain; // 남아있는 사람의 수
	int cross_num; // 다리를 건널 수 있는 사람의 수
	int current_num; // 다리를 건너고 있는 사람의 수
	int time; // 다리를 건너는데 걸리는 시간
	int start; // 다리를 건너기 시작한 시간
	int finish; // 다리를 다 건넌 시간
}NODE;

int B, P, C, T, total;
vector <NODE> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		cin >> B >> P;
		if (B == 0 && P == 0)
			break;

		B *= -1;

		v = vector<NODE>();

		for (int i = 0; i < B; i++)
		{
			cin >> C >> T;
			if (i == 0)
				v.push_back({ P, C, 0, T, 0, 0 });
			else
				v.push_back({ 0, C, 0, T, 0, 0 });
		}

		total = 0;
		int i = 0;
		while (total != P)
		{
			for (int b = 0; b < B; b++)
			{
				if (v[b].finish == i)
				{
					v[b].start = -1;
					v[b].finish = -1;
					v[b].remain -= v[b].current_num;
					if (b != B - 1)
						v[b + 1].remain += v[b].current_num;
					else
						total += v[b].current_num;
					v[b].current_num = 0;
				}
				if (total == P)
				{
					cout << i << '\n';
					break;
				}
				if (v[b].start == -1 && v[b].remain)
				{
					v[b].start = i;
					v[b].finish = i + v[b].time;
					v[b].current_num = (v[b].remain > v[b].cross_num ? v[b].cross_num : v[b].remain);
					
				}
			}
			i++;
		}
	}
}