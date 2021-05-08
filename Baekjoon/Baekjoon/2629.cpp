#include <iostream>
using namespace std;

int N, weight[31] = {0,}, M, target[8]={0,};
int dp[31][15001] = {0,};

void sol(int cnt, int result) {
    if (cnt > N) return;
    if (dp[cnt][result] == 1) return;

    dp[cnt][result] = 1;

    sol(cnt + 1, result + weight[cnt]);
    sol(cnt + 1, result);
    sol(cnt + 1, abs(result - weight[cnt]));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> weight[i];
    cin >> M;
    sol(0, 0);
    for (int i = 0; i < M; i++) {
        cin >> target[i];
        if (target[i] > 15000)
            cout << "N ";
        else if (dp[N][target[i]] == 1)
            cout << "Y ";
        else
            cout << "N ";
    }
}