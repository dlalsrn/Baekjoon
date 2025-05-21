#include <bits/stdc++.h>
using namespace std;
 
int N, M, K;
long long counting_sum = 0; // counting ary 풀이
 
vector <int> A;
vector <int> counting;
 
void Counting() {
    for (int i = 0; i < N; i++) {
        counting_sum += counting[K ^ A[i]];
        counting[A[i]]++;
        if (i >= M) {
            counting[A[i - M]]--;
        }
    }
}
 
int main(void) {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M >> K;
    
    A = vector<int>(N);
    counting = vector<int>(1 << 17, 0);
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    Counting();
 
    cout << counting_sum << '\n';
}
