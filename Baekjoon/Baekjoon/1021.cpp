#include <iostream>
#include <deque>
using namespace std;

int N, M, answer=0;
int position[51] = {0, };
deque<int> dq;
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> position[i];
    for (int i = 0; i < N; i++)
        dq.push_back(i + 1);
    for (int i = 0; i < M; i++) {
        int tmp = position[i];
        int loc = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (tmp == dq[j])
                break;
            else
                loc++;
        }
        int sz = dq.size();
        if ((sz / 2) - loc >= 0) {
            for (int j = 0; j < loc; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
            dq.pop_front();
        } else {
            for (int j = dq.size() - 1; j >= loc; j--) {
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
            dq.pop_front();
        }
    }
    cout << answer;
}