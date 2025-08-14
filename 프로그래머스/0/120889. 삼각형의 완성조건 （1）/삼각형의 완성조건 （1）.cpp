#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sides) {
    int answer;
    int sum = accumulate(sides.begin(), sides.end(), 0);
    int mx = *max_element(sides.begin(), sides.end());
    return answer = (sum - mx > mx ? 1 : 2);
}