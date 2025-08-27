#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    int sum;
    int N = elements.size();
    vector<int> v;

    int sz = elements.size() - 1;
    for (int i = 0; i < sz; i++)
    {
        elements.push_back(elements[i]);
    }

    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < elements.size(); j++)
        {
            sum += elements[j];
            
            if (j >= i)
            {
                v.push_back(sum);
                sum -= elements[j - i];
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return answer = v.size();
}