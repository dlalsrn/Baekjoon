#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    int sum = 0;
    int mn = sequence.size();
    int lIndex, rIndex;
    int l = 0, r = 0;

    while (r < sequence.size())
    {
        int n = sequence[r];

        if (sum + n < k)
        {
            sum += sequence[r++];
        }
        else if (sum + n > k)
        {
            sum -= sequence[l++];
        }
        else
        {
            if (mn > r - l)
            {
                mn = r - l;
                lIndex = l;
                rIndex = r;
            }

            sum -= sequence[l++];
            sum += sequence[r++];
        }
    }

    answer.push_back(lIndex);
    answer.push_back(rIndex);

    return answer;
}