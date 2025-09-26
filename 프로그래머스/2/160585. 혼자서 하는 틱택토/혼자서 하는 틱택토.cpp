#include <string>
#include <vector>
using namespace std;

int solution(vector<string> board)
{
    int cntO = 0;
    int cntX = 0;
    char ch[2] = { 'O', 'X' };

    for (string s : board)
    {
        for (char c : s)
        {
            if (c == 'O')
            {
                cntO++;
            }
            else if (c == 'X')
            {
                cntX++;
            }
        }
    }

    if (cntO < cntX || cntO > cntX + 1)
    {
        return 0;
    }

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == ch[k] && board[i][1] == ch[k] && board[i][2] == ch[k])
            {
                if (ch[k] == 'O' && cntO == cntX)
                {
                    return 0;
                }
                else if (ch[k] == 'X' && cntO == cntX + 1)
                {
                    return 0;
                }
            }

            if (board[0][i] == ch[k] && board[1][i] == ch[k] && board[2][i] == ch[k])
            {
                if (ch[k] == 'O' && cntO == cntX)
                {
                    return 0;
                }
                else if (ch[k] == 'X' && cntO == cntX + 1)
                {
                    return 0;
                }
            }
        }

        if (board[0][0] == ch[k] && board[1][1] == ch[k] && board[2][2] == ch[k])
        {
            if (ch[k] == 'O' && cntO == cntX)
            {
                return 0;
            }
            else if (ch[k] == 'X' && cntO == cntX + 1)
            {
                return 0;
            }
        }
        else if (board[0][2] == ch[k] && board[1][1] == ch[k] && board[2][0] == ch[k])
        {
            if (ch[k] == 'O' && cntO == cntX)
            {
                return 0;
            }
            else if (ch[k] == 'X' && cntO == cntX + 1)
            {
                return 0;
            }
        }
    }

    return 1;
}