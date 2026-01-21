#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

	map<int, int> countB;
    for (int x : B)
    {
        ++countB[x];
    }

    for (int i = 0; i < A.size(); ++i)
    {
        auto it = countB.upper_bound(A[i]);

        if (it != countB.end())
        {
            answer++;
            --(*it).second;

            if ((*it).second == 0)
            {
                countB.erase(it);
            }
        }
    }

    return answer;
}