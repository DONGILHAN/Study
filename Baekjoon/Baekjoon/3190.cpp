#include <iostream>
#include <queue>
using namespace std;

int N, K, L, board[100][100]={0, }, loc[2]={0, }, answer = 0;
queue<pair<int,int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d = 0;
int head[2] = {0, };
int tail[2] = {0, };
int flag = 0;
int main() {
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> loc[0] >> loc[1];
        board[loc[0] - 1][loc[1] - 1] = 1;
    }
    cin >> L;
    q.push(pair<int, int>(0, 0));
    board[head[0]][head[1]] = 2;
    for (int i = 0; i < L; i++) {
        int turnTime = 0;
        char direction;
        cin >> turnTime >> direction;
        while (answer < turnTime) {
            answer++;
            head[1] += dx[d];
            head[0] += dy[d];
            if (board[head[0]][head[1]] == 2) {
                flag = 1;
                break;
            } else if (head[0] >= N || head[0] < 0 || head[1] >= N || head[1] < 0) {
                flag = 1;
                break;
            }
            q.push(pair<int, int>(head[0], head[1]));
            if (board[head[0]][head[1]] == 0) {
                tail[0] = q.front().first;
                tail[1] = q.front().second;
                board[tail[0]][tail[1]] = 0;
                q.pop();
                board[head[0]][head[1]] = 2;
            } else if (board[head[0]][head[1]] == 1) {
                board[head[0]][head[1]] = 2;
            }
        }
        if (direction == 'D') {
            d++;
            if (d == 4)
                d = 0;
        } else if (direction == 'L') {
            d--;
            if (d == -1)
                d = 3;
        }
        if (flag == 1)
            break;
    }

    while (flag != 1) {
        answer++;
        head[1] += dx[d];
        head[0] += dy[d];
        if (board[head[0]][head[1]] == 2) {
            flag = 1;
            break;
        } else if (head[0] >= N || head[0] < 0 || head[1] >= N || head[1] < 0) {
            flag = 1;
            break;
        }
        board[head[0]][head[1]] = 2;
        q.push(pair<int, int>(head[0], head[1]));
        if (board[head[0]][head[1]] != 1) {
            tail[0] = q.front().first;
            tail[1] = q.front().second;
            board[tail[0]][tail[1]] = 0;
            q.pop();
            board[head[0]][head[1]] = 2;
        } else if (board[head[0]][head[1]] == 1) {
            board[head[0]][head[1]] = 2;
        }
    }

    cout << answer;
}