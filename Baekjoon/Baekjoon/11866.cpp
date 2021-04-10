#include <iostream>
#include <deque>
using namespace std;

int N, K;
deque<int> answer;
deque<int> dq;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        dq.push_back(i);
    while (answer.size() != N) {
        for (int i = 0; i < K - 1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        answer.push_back(dq.front());
        dq.pop_front();
    }
    cout << "<";
    while (answer.size() > 1) {
        cout << answer.front() + 1 << ", ";
        answer.pop_front();
    }
    cout << answer.front() + 1 << ">";
}