// 요격 시스템
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 1;

    sort(targets.begin(), targets.end());

    int minRight = targets[0][1];

    for (int i = 0; i < targets.size(); i++)
    {
        int left = targets[i][0];
        int right = targets[i][1];

        if (right < minRight)
        {
            minRight = right;
        }
        if (left >= minRight)
        {
            answer++;
            minRight = right;
        }
    }

    return answer;
}