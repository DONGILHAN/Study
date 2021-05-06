#include <iostream>
using namespace std;

int N, M, maxcost=0;
int memory[101] = {0, };
int cost[101] = {0, };
int dp[101][10001] = {0, };
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> memory[i];
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        maxcost += cost[i];
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 0; i <= maxcost; i++) {
            if (i - cost[j] >= 0)
                dp[j][i] = max(dp[j][i], dp[j - 1][i - cost[j]] + memory[j]);
            dp[j][i] = max(dp[j][i], dp[j - 1][i]);
        }
    }
    for (int i = 0; i <= maxcost; i++) {
        if (dp[N][i] >= M) {
            cout << i << endl;
            break;
        }
    }
}