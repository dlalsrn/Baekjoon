#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& v, int index, int sum, int target)
{
    if (index == v.size())
    {
        return sum == target ? 1 : 0;
    }

    return DFS(v, index + 1, sum + v[index], target) + DFS(v, index + 1, sum - v[index], target);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    answer = DFS(numbers, 0, 0, target);

    return answer;
}