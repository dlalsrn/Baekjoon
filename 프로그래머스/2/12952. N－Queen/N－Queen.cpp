// N-Queen
#include <string>
#include <vector>
using namespace std;

vector<vector<bool>> check;

bool checkRow(int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        if (check[r][i])
        {
            return false;
        }
    }

    return true;
}

bool checkCol(int n, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (check[i][c])
        {
            return false;
        }
    }

    return true;
}

bool checkDia(int n, int r, int c)
{
    for (int i = 0; r - i >= 0 && c - i >= 0; i++) // 좌측 상단
    {
        if (check[r - i][c - i])
        {
            return false;
        }
    }
    for (int i = 0; r + i < n && c + i < n; i++) // 우측 하단
    {
        if (check[r + i][c + i])
        {
            return false;
        }
    }
    for (int i = 0; r + i < n && c - i >= 0; i++) // 좌측 하단
    {
        if (check[r + i][c - i])
        {
            return false;
        }
    }
    for (int i = 0; r - i >= 0 && c + i < n; i++)
    {
        if (check[r - i][c + i]) // 우측 상단
        {
            return false;
        }
    }

    return true;
}

void BackTrack(int n, int row, int& answer)
{
    if (row == n)
    {
        answer++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (checkRow(n, row) && checkCol(n, col) && checkDia(n, row, col)) // queen을 놓을 수 있다면
        {
            check[row][col] = true;
            BackTrack(n, row + 1, answer);
            check[row][col] = false;
        }
    }
}

int solution(int n)
{
    int answer = 0;

    check = vector<vector<bool>>(n, vector<bool>(n, false));

    BackTrack(n, 0, answer);

    return answer;
}