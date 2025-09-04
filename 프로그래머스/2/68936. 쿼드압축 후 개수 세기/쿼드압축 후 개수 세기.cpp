#include <string>
#include <vector>

using namespace std;

int zero = 0;
int one = 0;

void Compress(vector<vector<int>>& arr, int y, int x, int sz)
{
    if (sz == 0)
    {
        return;
    }

    int n = arr[y][x];

    for (int i = y; i < y + sz; i++)
    {
        for (int j = x; j < x + sz; j++)
        {
            if (arr[i][j] != n)
            {
                sz /= 2;
                Compress(arr, y, x, sz);
                Compress(arr, y, x + sz, sz);
                Compress(arr, y + sz, x, sz);
                Compress(arr, y + sz, x + sz, sz);
                return;
            }
        }
    }

    if (n == 0)
    {
        zero++;
    }
    else
    {
        one++;
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    Compress(arr, 0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}