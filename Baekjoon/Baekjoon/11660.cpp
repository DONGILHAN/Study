#include <iostream>
using namespace std;
int N, M, x1, y1, x2, y2;
int board[1025][1025] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N >> M;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            cin >> board[x][y];
            board[x][y] = board[x][y] + board[x - 1][y] + board[x][y - 1] - board[x - 1][y - 1];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1] << "\n";
    }
}