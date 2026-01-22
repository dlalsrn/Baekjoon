#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;

    sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
		});

    int mxRight = routes[0][1];

    for (int i = 0; i < routes.size(); ++i)
    {
        int curLeft = routes[i][0];
        int curRight = routes[i][1];

        if (curLeft > mxRight)
        {
            ++answer;
            mxRight = curRight;
        }
    }

    return answer;
}