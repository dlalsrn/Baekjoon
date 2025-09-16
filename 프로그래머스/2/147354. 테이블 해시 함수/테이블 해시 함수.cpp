// 테이블 해시 함수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;

    auto cmp = [col](const vector<int>& a, const vector<int>& b) {
        if (a[col - 1] == b[col - 1])
            return a[0] > b[0];
        return a[col - 1] < b[col - 1];
		};

	sort(data.begin(), data.end(), cmp);

    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int sum = 0;
        for (int x : data[i])
        {
            sum += x % (i + 1);
        }
        answer ^= sum;
	}

    return answer;
}