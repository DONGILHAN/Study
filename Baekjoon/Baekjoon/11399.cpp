#include <iostream>
#include <algorithm>
using namespace std;

int N, T[1000]= {0, };
int dp[1000]={0, };
int main() {
    int answer = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> T[i];
    sort(T, T + N);
    dp[0] = T[0];
    for (int i = 1; i < N; i++)
        dp[i] = dp[i-1] + T[i];
    for (int i=0;i<N;i++)
        answer += dp[i];
    cout<<answer;
}