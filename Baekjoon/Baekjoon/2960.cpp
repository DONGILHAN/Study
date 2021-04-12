#include <iostream>
using namespace std;
int N, K, num[1001] = {0, }, cnt = 0, now, temp;
int main() {
    cin >> N >> K;
    while (cnt <= K) {
        now = 2;
        temp = 0;
        while (now <= N) {
            if (num[now] == 0)
                break;
            else
                now++;
        }
        temp = now;
        while (now <= N) {
            if (num[now] == 0) {
                num[now] = 1;
                cnt++;
            }
            if (cnt == K)
                break;
            else
                now += temp;
        }
        if (cnt == K)
            break;
    }
    cout << now;
}