#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, M, Max = 0;
    int board[1001][1001] = {0,};
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &board[i][j]);
            if (board[i][j] == 1) {
                board[i][j] = min(min(board[i - 1][j], board[i - 1][j - 1]), board[i][j - 1]) + 1;
                Max = max(board[i][j], Max);
            }
        }
    }
    printf("%d", Max * Max);
}