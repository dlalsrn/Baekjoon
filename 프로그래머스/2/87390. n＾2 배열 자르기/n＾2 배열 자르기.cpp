#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        int row = i / n;
        int col = i % n;
        answer.push_back(col < row ? row + 1 : col + 1);
    }

    return answer;
}