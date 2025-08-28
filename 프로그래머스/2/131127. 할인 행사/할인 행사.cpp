#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> count;

    for (int i = 0; i < discount.size(); i++)
    {
        count[discount[i]]++;

        if (i >= 9)
        {
            bool possible = true;
            for (int j = 0; j < want.size(); j++)
            {
                if (count[want[j]] < number[j])
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                answer++;
            }

            count[discount[i - 9]]--;
        }
    }
    return answer;
}