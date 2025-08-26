#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int m = *max_element(tangerine.begin(), tangerine.end());
    vector<int> v(m, 0);
    for(auto& t : tangerine){
        v[t - 1]++;
    }
    stable_sort(v.rbegin(), v.rend());
    for(int i = 0 ; i < v.size() ; i++){
        answer++;
        k -= v[i];
        if(k <= 0) return answer;
    }
    return answer;
}