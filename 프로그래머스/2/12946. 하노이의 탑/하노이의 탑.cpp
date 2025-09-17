// 하노이의 탑
#include <string>
#include <vector>

using namespace std;

void move(int start, int end, vector<vector<int>>& answer)
{
    vector<int> t;
    t.push_back(start);
    t.push_back(end);
    answer.push_back(t);
}

void hanoi(int N, int start, int end, int sub, vector<vector<int>>& answer)
{
    if (N == 1)
    {
        move(start, end, answer);
    }
    else
    {
        hanoi(N - 1, start, sub, end, answer);
        move(start, end, answer);
        hanoi(N - 1, sub, end, start, answer);
    }
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}