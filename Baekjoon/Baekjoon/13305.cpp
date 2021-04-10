#include <iostream>
using namespace std;

unsigned long long N, length[100001] = {0, }, price[100001] = {0, };
unsigned long long answer=0, Min, lennow;

int main() {
    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> length[i];
    for (int i = 1; i <= N; i++)
        cin >> price[i];
    Min = price[1];
    lennow = length[1];
    for (int i = 2; i < N; i++) {
        if (Min > price[i]) {
            answer += lennow * Min;
            lennow = length[i];
            Min = price[i];
        } else
            lennow += length[i];
    }
    answer += lennow * Min;
    cout << answer;
}