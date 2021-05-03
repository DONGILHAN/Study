#include <iostream>
using namespace std;

int R, C, T;
int board[50][50] = {0, };
int cleaner=0;
int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < R; i++) {
        if (board[i][0] == -1) {
            cleaner = i;
            break;
        }
    }
    for (int i = 0; i < T; i++) {
        int diffusion[50][50] = {0,};
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                int cnt = 0;
                if (x - 1 >= 0 && board[x - 1][y] != -1) {
                    diffusion[x - 1][y] += board[x][y] / 5;
                    cnt++;
                }
                if (x + 1 < R && board[x + 1][y] != -1) {
                    diffusion[x + 1][y] += board[x][y] / 5;
                    cnt++;
                }
                if (y - 1 >= 0 && board[x][y - 1] != -1) {
                    diffusion[x][y - 1] += board[x][y] / 5;
                    cnt++;
                }
                if (y + 1 < C && board[x][y + 1] != -1) {
                    diffusion[x][y + 1] += board[x][y] / 5;
                    cnt++;
                }
                diffusion[x][y] += board[x][y] - ((board[x][y] / 5) * cnt);
            }
        }
        for (int x = cleaner - 1; x > 0; x--)
            diffusion[x][0] = diffusion[x - 1][0];
        for (int y = 0; y < C - 1; y++)
            diffusion[0][y] = diffusion[0][y + 1];
        for (int x = 0; x < cleaner; x++)
            diffusion[x][C - 1] = diffusion[x + 1][C - 1];
        for (int y = C - 1; y > 1; y--)
            diffusion[cleaner][y] = diffusion[cleaner][y - 1];
        diffusion[cleaner][1] = 0;

        for (int x = cleaner + 2; x < R - 1; x++)
            diffusion[x][0] = diffusion[x + 1][0];
        for (int y = 0; y < C - 1; y++)
            diffusion[R - 1][y] = diffusion[R - 1][y + 1];
        for (int x = R - 1; x > cleaner + 1; x--)
            diffusion[x][C - 1] = diffusion[x - 1][C - 1];
        for (int y = C - 1; y > 1; y--)
            diffusion[cleaner + 1][y] = diffusion[cleaner + 1][y - 1];
        diffusion[cleaner + 1][1] = 0;

        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                board[x][y] = diffusion[x][y];
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++)
            answer += board[x][y];
    }
    cout << answer + 2;
}