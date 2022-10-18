// N과 M (9)
// next_permutation(v.begin(), v.end()) 라는 함수는 순열의 순서를 구해서 리턴해줌
// 원래 순서가 1, 2, 3, 4 인 v에서 위 함수를 돌리면 v가 1, 2, 4, 3 로 바뀜.
// prev_permutition도 있음. 이건 이전 순서의 순열로 변환
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
vector<int> last;
vector<int> v;
vector<int> ary;
set<vector<int>> s;

void DFS()
{
	if (v.size() == M)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		s.insert(v);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (v.size() != 0 && v.back() > ary[i])
				continue;
			v.push_back(ary[i]);
			if (s.find(v) == s.end())
				DFS();
			v.pop_back();
		}
	}
}

int main(void)
{
	int num;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ary.push_back(num);
	}
	sort(ary.begin(), ary.end());
	DFS();
}